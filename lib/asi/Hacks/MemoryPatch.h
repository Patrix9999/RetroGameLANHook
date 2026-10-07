#pragma once

#include <cstring>
#include <vector>
#include <functional>
#include <windows.h>

#include "untyped.h"

class MemoryPatch
{
protected:
	void Protect(const untyped target, DWORD &protection)
	{
		VirtualProtect(target, 5, protection, &protection);
		protection = 0;
	}

	void Unprotect(const untyped target, DWORD &protection)
	{
		VirtualProtect(target, 5, PAGE_EXECUTE_READWRITE, &protection);
	}

	template <typename T>
	void Apply(const untyped target, T data, size_t size)
	{
		DWORD protection = 0;

		Unprotect(target, protection);
		memcpy(target, (void*)data, size);
		Protect(target, protection);

		// flushing CPU cache
		FlushInstructionCache(GetCurrentProcess(), NULL, NULL);
	}

	template <typename T>
	void ApplySet(const untyped target, T data, size_t size)
	{
		DWORD protection = 0;

		Unprotect(target, protection);
		memset(target, data, size);
		Protect(target, protection);

		// flushing CPU cache
		FlushInstructionCache(GetCurrentProcess(), NULL, NULL);
	}

public:
	template <typename T>
	MemoryPatch(const untyped target, T data, size_t size, std::function<bool()> conditionCallback = nullptr)
	{
		if (!conditionCallback || (conditionCallback && conditionCallback()))
			ApplySet(target, data, size);
	};

	MemoryPatch(const untyped target, std::vector<BYTE> bytes, std::function<bool()> conditionCallback = nullptr)
	{
		if (!conditionCallback || (conditionCallback && conditionCallback()))
			Apply(target, &bytes[0], bytes.size());
	};

	template <typename T>
	MemoryPatch(const untyped target, T data, std::function<bool()> conditionCallback = nullptr)
	{
		if (!conditionCallback || (conditionCallback && conditionCallback()))
			Apply(target, &data, sizeof(data));
	};
};