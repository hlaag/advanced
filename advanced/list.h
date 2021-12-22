#pragma once
#include<assert.h>

//环形双向链表
template<class _Ty>
class list1
{
public:
	struct _Node;
	typedef _Node* _Nodeptr;
	struct _Node
	{
		_Ty _Value;
		_Nodeptr _Next, _Prev;
	};

	struct _Acc
	{
		typedef _Nodeptr& _Nodepref;
		typedef _Ty& _Vref;

		static _Nodepref _Next(_Nodeptr _P)
		{
			return ((_Nodepref)(*_P)._Next); 
		}

		static _Nodepref _Prev(_Nodeptr _P)//_P->_Next
		{
			return ((_Nodepref)(*_P)._Prev); //_P->_Prev
		}

		static _Vref _Value(_Nodeptr _P)
		{
			return ((_Vref)(*_P)._Value); //_P->_Value
		}
	};

	typedef size_t         size_type;
	typedef _Ty            value_type;
	typedef _Ty*           pointer_type;
	typedef const _Ty*     const_pointer_type;
	typedef _Ty&           reference;
	typedef const _Ty&     const_reference;
	typedef int            difference_type;
	


	class const_iterator1
	{
		//比较是否相同，++，--，取值
	public:
		int abcdefg = 10;
		const_iterator1()
		{
		}

		const_iterator1(_Nodeptr _P) :_Ptr(_P)
		{
		}

		const_iterator1(const_iterator1& _X) :_Ptr(_X._Ptr)
		{
		}

		const_reference operator* ()const
		{
			return _Acc::_Value(_Ptr);
		}

		const_iterator1 operator++()
		{
			_Ptr = _Acc::_Next(_Ptr);
			return *this;
		}

		const_iterator1 operator++(int)
		{
			const_reference _tmp = *this;
			++* this;
			return _tmp;
		}

		const_iterator1 operator--()
		{
			_Ptr = _Acc::_Prev(_Ptr);
			return *this;
		}
		const_iterator1 operator--(int)
		{
			const_iterator1 _tmp = *this;
			--* this;
			return _tmp;
		}

		bool operator==(const const_iterator1& _X)const
		{
			return _Ptr==_X._Ptr;
		}

		bool operator!=(const const_iterator1& _X)const
		{
			return !(*this == _X);
		}

		_Nodeptr _Mynode()const
		{
			return _Ptr;
		}
	protected:
		_Nodeptr _Ptr;
	};


	class iterator1 : public const_iterator1
	{
	public:
		iterator1()
		{
		}
		iterator1(_Nodeptr _P) :const_iterator1(_P)
		{
		}

		reference operator* ()const
		{
			return _Acc::_Value(this->_Ptr);
		}

		iterator1 operator++()
		{
			this->_Ptr = _Acc::_Next(this->_Ptr);
			return *this;
		}

		iterator1 operator++(int)
		{
			iterator1 _tmp = *this;
			++* this;
			return _tmp;
		}

		iterator1 operator--()
		{
			this->_Ptr = _Acc::_Prev(this->_Ptr);
			return *this;
		}
		iterator1 operator--(int)
		{
			const_reference _tmp = *this;
			--* this;
			return _tmp;
		}

		bool operator==(iterator1& _X)const
		{
			return _X._Ptr == this->_Ptr;
		}

		bool operator!=(iterator1& _X)const
		{
			return _X._Ptr != this->_Ptr;
		}
	};


	explicit list1() :_Head(_Buynode()),_Size()
	{
	}
	//尾插
	void push_back(const _Ty& v)
	{
		_Nodeptr _s = _Buynode(_Head,_Acc::_Prev(_Head));
		_s->_Value = v;
		_Acc::_Next(_Acc::_Prev(_s)) = _s;
		_Acc::_Prev(_Head) = _s;
		_Size++;
	}
	//头插
	void push_front(const _Ty& v)
	{

	}
	
	const_iterator1 begin()const
	{
		return const_iterator1(_Acc::_Next(_Head));
	}

	iterator1 begin()
	{
		return iterator1(_Acc::_Next(_Head));
	}

	const_iterator1 end()const
	{
		return const_iterator1(_Head);
	}

	iterator1 end()
	{
		return iterator1(_Head);
	}
protected:
	//申请节点,_Narg后继参数,_Parg前继参数   1.空参数即创建新节点  2.有参数，则_S->_Next=_Narg,_S->_Prev=_Parg
	_Nodeptr _Buynode(_Nodeptr _Narg=0,_Nodeptr _Parg=0) 
	{
		_Nodeptr _S= (_Nodeptr)malloc(sizeof(_Node));
		assert(_S != NULL);
		_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
		_Acc::_Prev(_S)= _Parg != 0 ? _Narg : _S;
		return _S;
	}
private:
	_Nodeptr _Head;
	size_type _Size;

};

