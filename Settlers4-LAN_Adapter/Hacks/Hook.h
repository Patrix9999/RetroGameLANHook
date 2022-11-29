#ifndef _HACKS_HOOK_H_
#define _HACKS_HOOK_H_

#include <cstring> // memcpy, std::size_t
#include <windows.h> // WinAPI functions

#include "untyped.h"

enum class InvokeType
{
	kDisabled,
	kNormal
};

template <typename T>
class Hook
{
private:
	void* address;
	void* detour;

	BYTE backup[5] = { 0x00, 0x00, 0x00, 0x00, 0x00 };
	DWORD protection = 0;

public:
	Hook(const untyped address, const untyped detour, const InvokeType invokeType = InvokeType::kNormal)
	{
		this->address = address;
		this->detour = detour;

		if (invokeType == InvokeType::kNormal)
			Attach();
	}

	~Hook()
	{		
		Detach();
	}

	bool Attach()
	{
		if (IsAttached())
			return false;

		// making backup of original 5 bytes
		memcpy(&backup, address, 5);

		// calculating relative address
		std::size_t offset = ((std::size_t)detour - (std::size_t)address - 5);

		// patching memory
		if (!Unprotect())
			return false;

		*reinterpret_cast<BYTE*>(address) = 0xE9; // JMP op code
		*reinterpret_cast<std::size_t*>(std::size_t(address) + 1) =  offset; // relative address

		if (!Protect())
			return false;

		// flushing CPU cache
		FlushInstructionCache(GetCurrentProcess(), NULL, NULL);
		return true;
	}

	bool Detach()
	{
		if (!IsAttached())
			return false;

		if (!Unprotect())
			return false;

		memcpy(address, backup, 5);
		memset(backup, 0, 5);
		
		if (!Protect())
			return false;

		return true;
	}

	bool IsAttached()
	{
		return 
			backup[0] != 0x00 ||
			backup[1] != 0x00 ||
			backup[2] != 0x00 ||
			backup[3] != 0x00 ||
			backup[4] != 0x00;
	}

	bool Protect()
	{
		if (!VirtualProtect(address, 5, protection, &protection))
			return false;

		protection = 0;
		return true;
	}

	bool Unprotect()
	{
		if (!VirtualProtect(address, 5, PAGE_EXECUTE_READWRITE, &protection))
			return false;

		return true;
	}

	bool IsProtected()
	{
		return protection != 0;
	}

	operator T()
	{
		return *(T)(address);
	}
};

template <typename T>
static inline Hook<T> CreateHook(const untyped& address, T detour, const InvokeType invokeType = InvokeType::kNormal)
{
	return Hook<T>(address, detour, invokeType);
}

#endif