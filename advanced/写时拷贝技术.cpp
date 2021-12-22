//理解深拷贝与浅拷贝
//掌握引用技术解决拷贝问题
//在计数实现中，理解写时拷贝技术

//读：浅拷贝，写：深拷贝   用户使用String类，String封装中间量StringPtr类，StringPtr包含数据char* data和技术use_count
//String的一般构造创建新的StringPtr，拷贝构造则赋值StringPtr，实现use_count的分开计数
//StringPtr封装use_count引用自增和自减操作，自减操作包括delete this

#include<iostream>
using namespace std;
class String;
ostream& operator<<(ostream& out, String& s);

//引用计数类
class StringPtr
{
	friend class String;
	friend ostream& operator<<(ostream& out, String& s);
public:
	StringPtr(const char* str):use_count(0)
	{
		if (str == NULL)
		{
			data = new char[1];
			data[0] = '\0';
		}
		else
		{
			data = new char[strlen(str) + 1];
			strcpy(data, str);
		}
	}
	StringPtr(const StringPtr& ptr) :use_count(0)
	{
		data = new char[strlen(ptr.data) + 1];
		strcpy(data, ptr.data);
	}
	StringPtr& operator=(const StringPtr& ptr)
	{
		if (this != &ptr)
		{
			delete[] data;
			data = new char[strlen(ptr.data) + 1];
			strcpy(data, ptr.data);
		}
		return *this;
	}
	void increment()
	{
		++use_count;
	}
	void decrement()
	{
		if (--use_count == 0)
		{
			delete this;
		}
		--use_count;
	}
	~StringPtr()
	{
		delete[] data;
		data = NULL;
	}
private:
	char* data;
	int use_count;
};


class String
{
	friend ostream& operator<<(ostream& out, String& s);
public:
	String(const char* str = "")
	{
		ptr = new StringPtr(str);
		ptr->increment();
	}
	String(const String& s)
	{
		ptr = s.ptr;
		ptr->increment();
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			ptr->decrement();
			ptr = s.ptr;
			ptr->increment();
		}
		return *this;
	}
	void to_upper()
	{
		if (ptr->use_count > 1)
		{
			StringPtr* newptr = new StringPtr(ptr->data);
			ptr->decrement();
			ptr = newptr;
			ptr->increment();
		}

		

		char* ch = ptr->data;
		while (*ch != '\0')
		{
			*ch -= 32;
			++ch;
		}
	}
	
	~String()
	{
		ptr->decrement();

	}

private:
	StringPtr* ptr;
};

ostream& operator<<(ostream& out, String& s)
{
	out << s.ptr->data;
	return out;
}

/*
int main()
{
	String s1("hello");
	String s2 = s1;
	String s3;
	s3 = s2;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	
	cout << "-------------------" << endl;

	s2.to_upper();
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}
*/

//class String
//{
//public:
//	String(const char* str = "")
//	{
//		if (str == NULL)
//		{
//			data = new char[1];
//			data[0] = '\0';
//		}
//		else
//		{
//			data = new char[strlen(str) + 1];
//			strcpy(data, str);
//		}
//		use_count++;
//	}
//	String(const String& s)
//	{
//		//data = new char[strlen(s.data) + 1];
//		//strcpy(data, s.data);
//		use_count++;
//		data = s.data;
//	}
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			/*delete[] data;
//			data = new char[strlen(s.data) + 1];
//			strcpy(data, s.data);*/
//			use_count++;
//			data = s.data;
//		}
//		return *this;
//	}
//	~String()
//	{
//		if (--use_count == 0)
//		{
//			delete[] data;
//			data = NULL;
//		}
//		
//	}
//private:
//	char* data;
//	static int use_count;
//};
//int String::use_count = 0;

