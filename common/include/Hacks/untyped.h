#ifndef _HACKS_UNTYPED_H_
#define _HACKS_UNTYPED_H_

typedef struct untyped__
{
	void* data;

	template <class T>
	untyped__(T x)
	{
		data = *reinterpret_cast<void**>(&x);
	}

	operator void* () const
	{
		return data;
	}

} untyped;

#endif