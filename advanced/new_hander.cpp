#include<iostream>
#include<new.h>
using namespace std;

//new_handerΪָ�����Ϊ�շ���Ϊ�յĺ�����ָ��
typedef void(*new_hander)();

class x
{
public:
	static new_hander set_new_hander(new_hander p);
	static void* operator new[](size_t size);
private:
	static new_hander currenthander;
	int data;
};

new_hander x::currenthander = 0;

//�����º���p������currenthander������ԭ��oldhander���ڱ���ԭ�е�hander
new_hander x::set_new_hander(new_hander p)
{
	new_hander oldhander = currenthander;
	currenthander = p;
	return oldhander;
}

void* x::operator new[](size_t size)
{
	if (size == 0)
	{
		size == 1;
	}
	void* result;
	while (1)
	{
		result = malloc(size);
		if (result != NULL)
		{
			return result;
		}

		//���ؾ�hander�����������µ�ǰhander
		new_hander globalhander = set_new_handler(0);
		set_new_handler(globalhander);
		//�����һ�����ص�hander��Ϊ�գ���ִ��hander�������׳�bad_alloc
		if (globalhander)
			(*globalhander)();
		else
			throw std::bad_alloc();
	}
}

void out_momory()
{
	cout << "out of momory" << endl;
	exit(1);
}

/*void main()
{
	//x* p = new x;
	x::set_new_hander(out_momory);
	try
	{
		x* p = new x[536870911];
	}
	catch(bad_alloc &e)
	{
		cout << e.what()<<endl;
	}
	
}*/

