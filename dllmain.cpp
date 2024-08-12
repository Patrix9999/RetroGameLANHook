#include "Hacks/Hook.h"

#include <string>
#include <iphlpapi.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Iphlpapi.lib")

static std::string GetAdapterFriendlyName(const char* GUID)
{
    std::string result = "";

    std::string regKey = "SYSTEM\\CurrentControlSet\\Control\\Network\\{4D36E972-E325-11CE-BFC1-08002BE10318}\\";
    regKey += GUID;
    regKey += "\\Connection";

    HKEY hKey;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, regKey.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return result;

    DWORD size = 0;
    if (RegQueryValueExA(hKey, "Name", NULL, NULL, NULL, &size) != ERROR_SUCCESS)
    {
        RegCloseKey(hKey);
        return result;
    }

    result.resize(size);
    if (RegQueryValueExA(hKey, "Name", NULL, NULL, reinterpret_cast<LPBYTE>(&result[0]), &size) != ERROR_SUCCESS)
    {
        RegCloseKey(hKey);
        return result;
    }
    result.resize(--size);

    RegCloseKey(hKey);
    return result;
}

static std::string GetAdapterIP(const char* adapterName)
{
    ULONG ipAdapterInfoSize = 0;
    PIP_ADAPTER_INFO pAdapterInfo = nullptr;

    if (GetAdaptersInfo(pAdapterInfo, &ipAdapterInfoSize) == ERROR_BUFFER_OVERFLOW)
        pAdapterInfo = (IP_ADAPTER_INFO*)malloc(ipAdapterInfoSize);

    if (GetAdaptersInfo(pAdapterInfo, &ipAdapterInfoSize) == NO_ERROR)
    {
        PIP_ADAPTER_INFO pAdapter = pAdapterInfo;
        while (pAdapter)
        {
            std::string adapterFriendlyName = GetAdapterFriendlyName(pAdapter->AdapterName);

            if (adapterFriendlyName == adapterName)
            {
                std::string result = pAdapter->IpAddressList.IpAddress.String;
                free(pAdapterInfo);

                return result;
            }

            pAdapter = pAdapter->Next;
        }
    }

    free(pAdapterInfo);
    return "";
}

static char adapterName[64];

static hostent* __stdcall hook_gethostbyname(const char* _hostname);
//auto Hook_gethostbyname = CreateHook(GetModuleHandleA(NULL), "ws2_32.dll", "gethostbyname", hook_gethostbyname);
auto Hook_gethostbyname = CreateHook((DWORD)GetProcAddress(GetModuleHandleA("ws2_32.dll"), "gethostbyname"), hook_gethostbyname);
static hostent* __stdcall hook_gethostbyname(const char* _hostname)
{
    Hook_gethostbyname.Detach();

    // We need to spoof hostname to use local dns computer hostname,
    // because some of the games like Age of Mythology for example,
    //  query ip address using custom domain
    DWORD hostnameSize = 0;
    GetComputerNameExA(ComputerNameDnsHostname, NULL, &hostnameSize);

    std::string hostname;
    hostname.resize(hostnameSize);

    GetComputerNameExA(ComputerNameDnsHostname, &hostname[0], &hostnameSize);

    std::string adapterIP = GetAdapterIP(adapterName);

	hostent* result = gethostbyname(hostname.c_str());
	int i = 0;

	while (result->h_addr_list[i] != 0)
	{
        struct in_addr addr;
        addr.s_addr = *(u_long*)result->h_addr_list[i];

        if (inet_ntoa(addr) == adapterIP)
            break;

		++i;
	}

	result->h_addr_list[0] = result->h_addr_list[i];
	result->h_addr_list[1] = NULL;

    Hook_gethostbyname.Attach();

	return result;
}

static void openConsole()
{
    AllocConsole();

    freopen("conin$", "r", stdin);
    freopen("conout$", "w", stdout);
    freopen("conout$", "w", stderr);
}

static void closeConsole()
{
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);

    FreeConsole();
}

static char moduleName[64];
VOID WINAPI onDllAttach(HMODULE hModule)
{
    CHAR iniFileName[] = "RetroGameLANHook.ini";
    CHAR iniFilePath[MAX_PATH] = {};

    DWORD result = GetModuleFileNameA(hModule, iniFilePath, sizeof(iniFilePath));
    if (result == 0 || result >= MAX_PATH)
        return;

    iniFilePath[strrchr(iniFilePath, '\\') - iniFilePath + 1] = NULL;
    strcat_s(iniFilePath, iniFileName);

    GetPrivateProfileStringA("Settings", "AdapterName", NULL, adapterName, sizeof(adapterName), iniFilePath);
}

VOID WINAPI onDllDetach()
{
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hModule);
			onDllAttach(hModule);
			break;

		case DLL_PROCESS_DETACH:
			onDllDetach();
			break;
	}

	return TRUE;
}

