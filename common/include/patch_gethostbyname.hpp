#pragma once

struct hostent* __stdcall patch_gethostbyname(const char* _hostname);