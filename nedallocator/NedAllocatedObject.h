#ifndef _NEDALLOCATED_OBJECT_H_
#define _NEDALLOCATED_OBJECT_H_

#include "NedAllocatorImpl.h"

class NedAllocatedObject
{
public:
	explicit NedAllocatedObject()
	{

	}
	~NedAllocatedObject()
	{

	}

	void* operator new(size_t sz)
	{
		return allocBytes(sz);
	}

	/// placement operator new
	void* operator new(size_t sz, void* ptr)
	{
		return ptr;
	}

	void* operator new[] ( size_t sz )
	{
		return allocBytes(sz);
	}

	void operator delete( void* ptr )
	{
		deallocBytes(ptr);
	}

	void operator delete( void* ptr, void* )
	{
		deallocBytes(ptr);
	}

	void operator delete[] ( void* ptr )
	{
		deallocBytes(ptr);
	}
};


#endif //_NEDALLOCATED_OBJECT_H_