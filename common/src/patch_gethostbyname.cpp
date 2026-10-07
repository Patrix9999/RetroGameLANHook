#include "original_functions.hpp"
#include "socket.hpp"

#include <iphlpapi.h>
#pragma comment(lib, "Iphlpapi.lib")

#include <string>

const char* GetSettingsAdapterName()
{
    static char adapterName[MAX_PATH] = {};
    static bool initialized = false;

    if (initialized)
        return adapterName;

    initialized = true;

    char iniFilePath[MAX_PATH] = {};

    DWORD result = GetModuleFileNameA(nullptr, iniFilePath, sizeof(iniFilePath));
    if (result == 0 || result >= MAX_PATH)
        return nullptr;

    char* separator = strrchr(iniFilePath, '\\');
    if (!separator)
        return nullptr;

    separator[1] = '\0';

    if (strcat_s(iniFilePath, "RetroGameLANHook.ini") != 0)
        return nullptr;

    if (GetPrivateProfileStringA("Settings", "AdapterName", nullptr, adapterName, sizeof(adapterName), iniFilePath) == 0)
        return nullptr;

    return adapterName;
}

static std::string GetAdapterFriendlyName(const char* GUID)
{
    std::string result;

    std::string regKey = R"(SYSTEM\CurrentControlSet\Control\Network\{4D36E972-E325-11CE-BFC1-08002BE10318}\)";
    regKey += GUID;
    regKey += "\\Connection";

    HKEY hKey;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, regKey.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return result;

    DWORD size = 0;
    if (RegQueryValueExA(hKey, "Name", nullptr, nullptr, nullptr, &size) != ERROR_SUCCESS)
    {
        RegCloseKey(hKey);
        return result;
    }

    result.resize(size);
    if (RegQueryValueExA(hKey, "Name", nullptr, nullptr, reinterpret_cast<LPBYTE>(&result[0]), &size) != ERROR_SUCCESS)
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
        pAdapterInfo = static_cast<IP_ADAPTER_INFO*>(malloc(ipAdapterInfoSize));

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

hostent* __stdcall patch_gethostbyname(const char* _hostname)
{
    // We need to spoof hostname to use local dns computer hostname,
    // because some of the games like Age of Mythology for example,
    //  query ip address using custom domain
    DWORD hostnameSize = 0;
    GetComputerNameExA(ComputerNameDnsHostname, nullptr, &hostnameSize);

    std::string hostname;
    hostname.resize(hostnameSize);

    GetComputerNameExA(ComputerNameDnsHostname, &hostname[0], &hostnameSize);
    static const auto adapterName = GetSettingsAdapterName();
    static const std::string adapterIP = GetAdapterIP(adapterName);

    hostent* result = _gethostbyname(hostname.c_str());
    int i = 0;

    while (result->h_addr_list[i] != nullptr)
    {
        in_addr addr {};
        addr.s_addr = *reinterpret_cast<u_long*>(result->h_addr_list[i]);

        if (_inet_ntoa(addr) == adapterIP)
            break;

        ++i;
    }

    result->h_addr_list[0] = result->h_addr_list[i];
    result->h_addr_list[1] = nullptr;

    return result;
}