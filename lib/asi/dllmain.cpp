#include "Hacks/Hook.h"
#include "common/socket.hpp"
#include "patch_gethostbyname.hpp"

#pragma comment(lib, "ws2_32.lib")

static hostent* __stdcall hook_gethostbyname(const char* _hostname);
auto Hook_gethostbyname = CreateHook((DWORD)GetProcAddress(GetModuleHandleA("ws2_32.dll"), "gethostbyname"), hook_gethostbyname);
static hostent* __stdcall hook_gethostbyname(const char* _hostname)
{
    Hook_gethostbyname.Detach();

	auto result = patch_gethostbyname(_hostname);

    Hook_gethostbyname.Attach();

	return result;
}