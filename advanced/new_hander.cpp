#include<iostream>
#include<new.h>
using namespace std;

//new_hander为指向参数为空返回为空的函数的指针
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

//传入新函数p，更新currenthander，返回原有oldhander用于保存原有的hander
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

		//返回旧hander，并用它更新当前hander
		new_hander globalhander = set_new_handler(0);
		set_new_handler(globalhander);
		//如果上一步返回的hander不为空，则执行hander，否则抛出bad_alloc
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

