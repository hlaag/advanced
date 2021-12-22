#pragma once
#ifndef _SP_COUNTED_IMPL_XX_H
#define _SP_COUNTED_IMPL_XX_H
#include<iostream>
using namespace std;

template<class T>
class sp_counted_impl_xx:public sp_counted_base
{
public:
	sp_counted_impl_xx(T* p) :px_(p)
	{
		cout << "create sp_counted_impl_xx" << endl;
	}
	~sp_counted_impl_xx()
	{
		cout << "free sp_counted_impl_xx" << endl;
	}
	virtual void dispose()
	{
		delete px_;
	}
private:
	T* px_;
};

template<class P,class D>
class sp_counted_impl_pd :public sp_counted_base
{
public:
	sp_counted_impl_pd(P p,D d):ptr(p),del(d)
	{

	}
	virtual void dispose()
	{
		del(ptr);
	}
private:
	P ptr;
	D del;
};



#endif