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
	//���÷����������const���ܻ�����õ�ֵ�����޸ģ�Υ��const����
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
	//int& b1 = t1.getValue();  return�ľ��г��ͣ���ͨ�����޷����ܳ���
	const int& c1 = t1.getValue();

	int a2 = t2.getValue();
	//int& b2 = t2.getValue(); 
	const int& c2 = t2.getValue();

	int a1 = t1.getRef();
	int& b1 = t1.getRef(); // ���÷���û�г�����
	const int& c1 = t1.getRef();

	int a2 = t2.getRef();
	int& b2 = t2.getRef(); 
	const int& c2 = t2.getRef();

	int* a1 = t1.getPtr();
	int*& b1 = t1.getPtr();//��
	const int*& c1 = t1.getPtr();//�� data�ǳ���
	int* const & c11 = t1.getPtr(); //�� data��ַ�ǳ���

	int* a2 = t2.getPtr();
	int*& b2 = t2.getPtr();
	const int*& c2 = t2.getPtr();
	int* const& c22 = t2.getPtr(); 
	
}
*/
//���ݳ�ԱΪֵ��Ա