#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "proxy.hpp"

// predeclarations

#include <inaddr.h>

struct hostent;

inline hostent* WINAPI _gethostbyname(const char* addr) { return CALL_ORIGINAL_FUNC_AS(_gethostbyname, gethostbyname)(addr); }
inline char* WINAPI _inet_ntoa (in_addr in) { return CALL_ORIGINAL_FUNC_AS(_inet_ntoa, inet_ntoa)(in); }