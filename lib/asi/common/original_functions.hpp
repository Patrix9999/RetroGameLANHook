#pragma once

#include <WinSock2.h>

inline hostent* WINAPI _gethostbyname(const char* addr) { return gethostbyname(addr); }
inline char* WINAPI _inet_ntoa (in_addr in) { return inet_ntoa(in); }