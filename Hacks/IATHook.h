#pragma once

#include <Windows.h> // WinAPI functions

#include "untyped.h"
#include "InvokeType.h"

inline DWORD RVA(HMODULE handle, DWORD offset) {
	return reinterpret_cast<DWORD>(handle) + offset;
};

template <typename T>
class IATHook
{
private:
	HMODULE module;
	const char* target_dll;

	const char* func_signature;
	void* detour;
	void* backup;

	DWORD protection = 0;

public:
	IATHook(const HMODULE module, const char* target_dll, const char* func_signature, const untyped detour, const InvokeType invokeType = InvokeType::kNormal)
	{
		this->module = module;
		this->target_dll = target_dll;

		this->func_signature = func_signature;
		this->detour = detour;
		this->backup = nullptr;

		if (invokeType == InvokeType::kNormal)
			Attach();
	}

	~IATHook()
	{
		Detach();
	}

	bool SetModule(HMODULE module)
	{
		if (IsAttached())
			return false;

		this->module = module;
		return true;
	}

	bool Attach()
	{
		if (IsAttached())
			return false;

		return PatchIAT_BySignature(detour, true);
	}

	bool Detach()
	{
		return PatchIAT_BySignature(backup, false);
	}

	bool IsAttached()
	{
		return backup != nullptr;
	}

	bool Protect()
	{
		if (!VirtualProtect(address, 4, protection, &protection))
			return false;

		protection = 0;
		return true;
	}

	bool Unprotect()
	{
		if (!VirtualProtect(address, 4, PAGE_READWRITE, &protection))
			return false;

		return true;
	}

	bool IsProtected()
	{
		return protection != 0;
	}

	operator T()
	{
		return reinterpret_cast<T>(backup);
	}

private:
	inline DWORD VirtualAddress(HMODULE module, DWORD offset)
	{
		return reinterpret_cast<DWORD>(module) + offset;
	}

	inline PIMAGE_IMPORT_DESCRIPTOR GetImportDescriptor()
	{
		PIMAGE_DOS_HEADER dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(module);
		if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE)
			return nullptr;

		PIMAGE_NT_HEADERS ntHeader = reinterpret_cast<PIMAGE_NT_HEADERS>(VirtualAddress(module, dosHeader->e_lfanew));
		if (ntHeader->Signature != IMAGE_NT_SIGNATURE)
			return nullptr;

		PIMAGE_IMPORT_DESCRIPTOR importDescriptor = reinterpret_cast<PIMAGE_IMPORT_DESCRIPTOR>(VirtualAddress(module, ntHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress));
		for (int i = 0; importDescriptor[i].Characteristics != 0; ++i)
		{
			LPCSTR current_dll = reinterpret_cast<LPCSTR>(VirtualAddress(module, importDescriptor[i].Name));
			if (!importDescriptor[i].FirstThunk || _stricmp(current_dll, target_dll) != 0)
				continue;

			return &importDescriptor[i];
		}

		return nullptr;
	}

	inline bool PatchIAT_BySignature(void* func, bool attach)
	{
		PIMAGE_IMPORT_DESCRIPTOR importDescriptor = GetImportDescriptor();
		if (importDescriptor == nullptr)
			return false;

		PIMAGE_THUNK_DATA importNameTableEntry = reinterpret_cast<PIMAGE_THUNK_DATA>(VirtualAddress(module, importDescriptor->OriginalFirstThunk));
		PIMAGE_THUNK_DATA importAddressTableEntry = reinterpret_cast<PIMAGE_THUNK_DATA>(VirtualAddress(module, importDescriptor->FirstThunk));

		while (importNameTableEntry->u1.AddressOfData != NULL)
		{
			PIMAGE_IMPORT_BY_NAME importedFunction = reinterpret_cast<PIMAGE_IMPORT_BY_NAME>(VirtualAddress(module, importNameTableEntry->u1.AddressOfData));
			if (strcmp(importedFunction->Name, func_signature) == 0)
			{
				DWORD oldProtect;

				VirtualProtect(importAddressTableEntry, sizeof(func), PAGE_READWRITE, &oldProtect);
				backup = attach ? reinterpret_cast<void*>(importAddressTableEntry->u1.Function) : nullptr;
				importAddressTableEntry->u1.Function = reinterpret_cast<DWORD>(func);
				VirtualProtect(importAddressTableEntry, sizeof(func), oldProtect, &oldProtect);

				return true;
			}

			++importNameTableEntry;
			++importAddressTableEntry;
		}

		return false;
	}
};

template <typename T>
static inline IATHook<T> CreateHook(const HMODULE root, const char* target_dll, char* func_signature, T detour, const InvokeType invokeType = InvokeType::kNormal)
{
	return IATHook<T>(root, target_dll, func_signature, detour, invokeType);
}