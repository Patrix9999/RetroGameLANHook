#include "stdafx.h"

#include <string>
#include <iphlpapi.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Iphlpapi.lib")

std::string GetAdapterFriendlyName(const char* GUID)
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

std::string GetAdapterIP(std::string adapterName)
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

hostent* (__stdcall*& ptr_gethostbyname)(const char*) = *(hostent * (__stdcall**)(const char*))0x00A31C14;
hostent* __stdcall proxy_gethostbyname(const char* name)
{
    std::string adapterIP = GetAdapterIP(adapterName);

	hostent* result = gethostbyname(name);
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

	return result;
}

bool initWinSockLibrary();
HOOK Ivk_initWinSockLibrary AS(0x0057E5D0, initWinSockLibrary);
bool initWinSockLibrary()
{
	Ivk_initWinSockLibrary.Detach();

	bool result = Ivk_initWinSockLibrary();
	ptr_gethostbyname = proxy_gethostbyname;

	Ivk_initWinSockLibrary.Attach();

	return result;
}

VOID WINAPI onDllAttach(HMODULE hModule)
{
    CHAR iniFilePart[] = "\\Exe\\plugins\\LAN_Adapter.ini";
    CHAR iniFilePath[MAX_PATH] = {};

    DWORD result = GetCurrentDirectoryA(MAX_PATH, iniFilePath);

    if (result != 0 && result <= MAX_PATH - sizeof(iniFilePart))
        strcat_s(iniFilePath, iniFilePart);

    GetPrivateProfileStringA("LAN_Adapter", "AdapterName", NULL, adapterName, sizeof(adapterName), iniFilePath);
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

