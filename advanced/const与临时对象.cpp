#include<iostream>
using namespace std;

class Test
{
public:
	Test(int d = 0) :data(d)
	{
	}
	int getValue()
	{
		return data;
	}
	int getValue()const
	{
		return data;
	}
	int& getRef()
	{
		return data;
	}
	//引用返回如果不是const可能会对引用的值发生修改，违背const函数
	const int& getRef()const
	{
		return data;
	}
	int* getPtr()
	{
		return &data;
	}
	const int* getPtr()const
	{
		return &data;
	}
private:
	int data;
};

/*
void main()
{
	Test t1(10);
	const Test t2(100);

	
	int a1 = t1.getValue();
	//int& b1 = t1.getValue();  return的具有常型，普通引用无法接受常量
	const int& c1 = t1.getValue();

	int a2 = t2.getValue();
	//int& b2 = t2.getValue(); 
	const int& c2 = t2.getValue();

	int a1 = t1.getRef();
	int& b1 = t1.getRef(); // 引用返回没有常属性
	const int& c1 = t1.getRef();

	int a2 = t2.getRef();
	int& b2 = t2.getRef(); 
	const int& c2 = t2.getRef();

	int* a1 = t1.getPtr();
	int*& b1 = t1.getPtr();//错
	const int*& c1 = t1.getPtr();//错 data是常量
	int* const & c11 = t1.getPtr(); //对 data地址是常量

	int* a2 = t2.getPtr();
	int*& b2 = t2.getPtr();
	const int*& c2 = t2.getPtr();
	int* const& c22 = t2.getPtr(); 
	
}
*/
//数据成员为值成员