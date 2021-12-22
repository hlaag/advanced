#pragma once
#ifndef _SHARED_COUNT_H
#define _SHARED_COUNT_H
#include"sp_counted_base.h"
#include"sp_counted_impl_xx.h"
#include<iostream>
using namespace std;

class shared_count
{
public:
	shared_count()
	{
		cout << "create shared_count" << endl;
	}
	shared_count(const shared_count& cs):pi_(cs.pi_)
	{
		if (pi_ != 0)
		{
			pi_->add_ref_copy();
		}
	}
	template<class Y,class D>
	shared_count(Y* p, D d):pi_(0)
	{
		typedef Y* P;
		pi_ = new sp_counted_impl_xx<P, D>(p, d);
	}
	template<class Y>
	shared_count(Y* p) :pi_(new sp_counted_impl_xx<Y>(p)) //子类对父类赋值，子类包含继承的use_count和自己的px_
	{
		cout << "create shared_count" << endl;
	}
	long use_count()const
	{
		return pi_ != 0 ? pi_->use_count() : 0;
	}
	~shared_count()
	{
		cout << "free shared_count" << endl;
		if (pi_ != 0)
		{
			pi_->release();
		}
	}
	bool unique()const
	{
		return use_count() == 1;
	}
	void swap(shared_count& r)
	{
		sp_counted_base* tmp=r.pi_;
		r.pi_ = pi_;
		pi_ = tmp;
	}
private:
	sp_counted_base* pi_;
};


#endif