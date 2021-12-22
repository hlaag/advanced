#pragma once
 
template<class T>
void check_array_delete(T* x)
{
	delete[] x;
}

template<class T>
struct check_array_deleter
{
	void operator() (T* x)const
	{
		check_array_delete(x);
	}
};