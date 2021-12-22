#pragma once
#ifndef _SHARED_PTR_H
#define _SHARED_PTR_H
#include"shared_count.h"
#include<iostream>
using namespace std;

template<class T>
class shared_ptr1
{
public:
	shared_ptr1(T* p=0):px(p),pn(p)
	{
		cout << "Create shared_ptr1" << endl;
	}
	template<class Y,class D>
	shared_ptr1(Y* p, D d):px(p),pn(p,d)
	{

	}


	shared_ptr1(const shared_ptr1<T>& ptr1):px(ptr1.px),pn(ptr1.pn)
	{

	}
	typedef shared_ptr1<T> this_type;
	shared_ptr1<T>& operator=(const shared_ptr1<T>& r)
	{
		if (this != &r)
		{
			this_type(r).swap(*this);
		}
		return *this;
	}
	void swap(shared_ptr1<T>& other)
	{
		std::swap(px, other.px);
		pn.swap(other.pn);
	}
	T& operator*()
	{
		return *(get());
	}
	T* get()const
	{
		return px;
	}
	T* operator->()
	{
		return get();
	}
	long use_count()const
	{
		return pn.use_count();
	}
	bool unique()const
	{
		return pn.unique();
	}
	~shared_ptr1()
	{
		cout << "free shared_ptr1" << endl;
	}
private:
	T* px;
	shared_count pn; //调用有参构造
};

#endif