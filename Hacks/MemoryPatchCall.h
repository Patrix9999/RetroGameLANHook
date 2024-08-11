#ifndef _HACKS_MEMORY_PATCH_CALL
#define _HACKS_MEMORY_PATCH_CALL

#include "MemoryPatch.h"

class MemoryPatchCall : public MemoryPatch
{
public:
	MemoryPatchCall(untyped target, untyped address, std::function<bool()> conditionCallback = nullptr) :
		MemoryPatch(target, BYTE(0xE8), conditionCallback)
	{
		if (!conditionCallback || (conditionCallback && conditionCallback()))
		{
			DWORD offset = (DWORD)address.data - (DWORD)target.data - 5;
			Apply((DWORD)target.data + 1, &offset, 4);
		}
	};
};

#endif