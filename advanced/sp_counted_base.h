#pragma once
#ifndef _SP_COUNTED_BASE_H
#define _SP_COUNTED_BASE_H
#include<iostream>
using namespace std;

class sp_counted_base
{
public:
	sp_counted_base():use_count_(1)
	{
		cout << "create sp_counted_base" << endl;
	}
	virtual ~sp_counted_base()
	{
		cout << "free sp_counted_base" << endl;
	}
	virtual void dispose() = 0;
	void release()
	{
		if (--use_count_ == 0)
		{
			dispose();
			delete this;
		}
	}
	long use_count()const
	{
		return use_count_;
	}
	void add_ref_copy()
	{
		++use_count_;
	}
private:
	long use_count_;
};

#endif