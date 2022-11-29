#ifndef _HACKS_MEMORY_PATCH
#define _HACKS_MEMORY_PATCH

#include <cstring>
#include <vector>
#include <windows.h>

#include "UNTYPED.h"

class MemoryPatch
{
private:
	void Protect(const untyped target, DWORD &protection)
	{
		VirtualProtect(target, 5, protection, &protection);
		protection = 0;
	}

	void Unprotect(const untyped target, DWORD &protection)
	{
		VirtualProtect(target, 5, PAGE_EXECUTE_READWRITE, &protection);
	}

	template <class T>
	void Apply(const untyped target, T data, size_t size)
	{
		DWORD protection = 0;

		Unprotect(target, protection);
		memcpy(target, (void*)data, size);
		Protect(target, protection);

		// flushing CPU cache
		FlushInstructionCache(GetCurrentProcess(), NULL, NULL);
	}

public:
	MemoryPatch(const untyped target, std::vector<BYTE> bytes)
	{
		Apply(target, &bytes[0], bytes.size());
	};

	template <typename T>
	MemoryPatch(const untyped target, T data)
	{
		Apply(target, &data, sizeof(data));
	};
};

#endif