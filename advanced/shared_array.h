#ifndef _SHARED_ARRAY_H
#define _SHARED_ARRAY_H
#include"shared_count.h"
#include"check_delete.h"

template<class T>
class shared_array1
{
public:
	typedef check_array_deleter<T> deleter;
	shared_array1(T* p=0):px(p),pn(p,deleter())
	{

	}

private:
	T* px;
	shared_count pn;
};





#endif 
