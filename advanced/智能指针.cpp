//auto_ptr(VC) auto_ptr(VS)  boost��  scoped_ptr  scoped_array  shared_ptr  shared_array  weak_ptr  intrusive_ptr 

#include<boost/smart_ptr.hpp>
#include<iostream>
#include<memory>
#include<string>
#include"shared_ptr.h"
#include"shared_array.h"

using namespace std;
using namespace boost;

//VC
template<class _Ty>
class auto_ptr1
{
public:
	auto_ptr1(_Ty* _P=0):_owns(_P!=0),_ptr(_P)
	{

	}
	auto_ptr1(const auto_ptr1<_Ty>& _Y):_owns(_Y._owns),_ptr(_Y.release())
	{
	}
	auto_ptr1<_Ty>& operator=(const auto_ptr1<_Ty>& _Y)
	{
		if (this != &_Y)
		{
			if (_ptr != _Y._ptr)
			{
				if (_owns)//����ֵ������ָ���Ƿ�����ָ��������Ҫdelete��ֹ�ڴ�й¶
				{
					delete _ptr;
					_owns = _Y._owns;
				}
				else if (_Y._owns)//_owns��false��Ϊtrue
				{
					_owns = true;
				}
				_ptr = _Y.release();
			}
		}
		return *this;
	}
	_Ty& operator*()const
	{
		return *_ptr;
	}
	_Ty* operator->()const
	{
		return _ptr;
	}
	//��������ʱ������������ָ���ӵ��Ȩ��Ϊfalse���������ʱ�����ٴ�delete
	_Ty* release()const
	{
		//((auto_ptr1<_Ty>*)this)->_owns = false;
		//(const_cast<auto_ptr1<_Ty>*>(this))->_owns = false;
		_owns = false;
		return _ptr;
	}
	~auto_ptr1()
	{
		if (_owns)
		{
			delete _ptr;
		}
	}
private:
	mutable bool _owns;
	_Ty* _ptr;
};

//VS
template<class _Ty>
class auto_ptr2
{
public:
	auto_ptr2(_Ty* p=0):_ptr(p)
	{
	}
	auto_ptr2(auto_ptr2<_Ty>& _Y) :_ptr(_Y.release())
	{

	}
	_Ty* release()
	{
		_Ty* temp = _ptr;
		_ptr = NULL;
		return temp;
	}
	auto_ptr2<_Ty>& operator=(auto_ptr2<_Ty>& _Y)
	{
		reset(_Y.release());
		return *this;
	}
	void reset(_Ty* _p)
	{
		if (_p != _ptr && _ptr != 0)
		{
			delete _ptr;
		}
		_ptr = _p;
	}
	~auto_ptr2()
	{
		delete _ptr;
	}
	_Ty& operator*()const
	{
		return *(get());
	}
	_Ty* operator->()const
	{
		return get();
	}
	_Ty* get()const
	{
		return _ptr;
	}
private:
	_Ty* _ptr;
};

//scoped_ptr
template<class T>
class scoped_ptr1
{
public:
	scoped_ptr1(T *p=0):px(p)
	{
	}
	~scoped_ptr1()
	{
		delete px;
	}
	T& operator*()
	{
		return *px;
	}
	T* operator->()
	{
		return px;
	}
	void reset(T *p=0)
	{
		if (px != p && px != 0)
		{
			delete px;		
		}
		px = p;
	}
private:
	scoped_ptr1(const scoped_ptr1<T>&);
	scoped_ptr1& operator=(const scoped_ptr1<T>&);
	T* px;
};

//scoped_array
//û������*��->
template<class T>
class scoped_array1
{
public:
	scoped_array1(T* t = 0) :px(t)
	{
	}
	~scoped_array1()
	{
		delete[] px;
	}
	typedef scoped_array1<T> this_type;
	void reset(T *t=0)
	{
		this_type(t).swap(*this);
	}
	void swap(scoped_array1& b)
	{
		T* tmp = b.px;
		b.px = px;
		px = tmp;
	}
private:
	T* px;
	scoped_array1(scoped_array1<T> const&);
	scoped_array1& operator=(scoped_array1<T> const&);
	void operator==(scoped_array1<T> const&);
	void operator!=(scoped_array1<T> const&);
};

//shared_ptr


/*
int main()
{
	int* p = new int(10);
	shared_ptr1<int> ps(p);
	cout << ps.unique() << endl;
	shared_ptr1<int> ps1= ps;
	cout << ps.unique() << endl;
	{
		shared_ptr1<int> ps2 = ps;
		cout << "�ֲ�:" << ps.use_count() << endl;
		cout << "�ֲ�:" << ps.unique() << endl;
	}
	cout << "�ⲿ:" << ps.use_count() << endl;
	cout << "�ⲿ:" << ps.unique() << endl;
	
}
*/


//void main()
//{
//	int* p = new int(1);
//	auto_ptr<int> pa(p);
//	cout << *pa << endl;
//	string* s = new string("hello");
//	auto_ptr<string> ps(s);
//	cout << ps->size() << endl;
//}

