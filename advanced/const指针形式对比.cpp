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

	int* a1 = t1.getVal();//��
	int* &b1 = t1.getVal();//��
	const int*& c1 = t1.getVal();//��
	int* const& c1 = t1.getVal();//��

	int* a2 = t2.getVal();//��
	int*& b2 = t2.getVal();//��
	const int*& c2 = t2.getVal();//��
	int* const& c2 = t2.getVal();//��

	int* a1 = t1.getRef();
	int*& b1 = t1.getRef();
	const int*& c1 = t1.getRef();
	int* const& c1 = t1.getRef();
}
*/