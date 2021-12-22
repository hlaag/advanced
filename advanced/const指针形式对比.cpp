#include<iostream>
using namespace std;

class Test
{
public:
	Test(int d=0):m_ptr(new int(d))
	{
	}
	int* getVal()
	{
		return m_ptr;
	}
	int* getVal()const
	{
		return m_ptr;
	}
	int*& getRef()
	{
		return m_ptr;
	}
	int* const& getRef()const
	{
		return m_ptr;
	}

private:
	int* m_ptr;
};
/*
void main()
{
	Test t1(10);
	const Test t2(200);

	int* a1 = t1.getVal();//对
	int* &b1 = t1.getVal();//错
	const int*& c1 = t1.getVal();//错
	int* const& c1 = t1.getVal();//对

	int* a2 = t2.getVal();//对
	int*& b2 = t2.getVal();//错
	const int*& c2 = t2.getVal();//错
	int* const& c2 = t2.getVal();//对

	int* a1 = t1.getRef();
	int*& b1 = t1.getRef();
	const int*& c1 = t1.getRef();
	int* const& c1 = t1.getRef();
}
*/