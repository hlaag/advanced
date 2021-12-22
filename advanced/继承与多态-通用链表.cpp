//1、掌握继承与多态  2、虚函数，抽象类接口  3、通过多态的形式，建立通用链表

#include<iostream>
#include<assert.h>
#include"string.h"
using namespace std;

//父类Object
class Object
{
public:
	Object()
	{
	}
	virtual ~Object()
	{
	}
	virtual void print()const = 0;//接口
	virtual bool compare(Object * pb) const = 0;
};

class List;


class ListNode
{
public:
	friend class List;
	ListNode()
	{
		data = NULL;
		next = NULL;
	}
	ListNode(Object* pobj)
	{
		data = pobj;
		next = NULL;
	}
	~ListNode()
	{
		delete data;
	}

private:
	Object* data;
	ListNode* next;
};

class List
{
public:
	List()
	{
		head = tail = new ListNode();
	}
	~List()
	{
		ListNode* p = head->next;
		while (p != NULL)
		{
			head->next = p->next;
			delete p;
			p = head->next;
		}
		delete head;
		head = tail = NULL;
	}
	void push_Back(Object* pb)
	{
		ListNode* s = new ListNode(pb);
		assert(s != NULL);
		tail->next = s;
		tail = s;
	}
	void insertOrder(Object* pb)
	{
		ListNode* s = new ListNode(pb);
		ListNode* q = head;
		ListNode* p = head->next;
		while (p != NULL&&p->data->compare(s->data))
		{
			q = p;
			p = p->next;
		}
		s->next = p;
		q->next = s;
		if (p == NULL)
		{
			tail = s;
		}
	}
	void printList()const
	{
		ListNode* p = head->next;
		while (p != NULL)
		{
			p->data->print(); //顶层Object多态调用print函数
			p = p->next;
		}
		cout << "Nul." << endl;
	}
private:
	ListNode* head;
	ListNode* tail;
};
//
class IntObject :public Object
{
public:
	IntObject(int d=0):data(d)
	{
	}
	~IntObject()
	{
		cout << "FREE INT" << endl;
	}
	void print()const
	{
		cout << data << "-->";
	}
	bool compare(Object* pb) const
	{
		IntObject* pi = dynamic_cast<IntObject*>(pb);
		assert(pi != NULL);
		return data<pi->data;
	}
private:
	int data;
};

class StringObject :public Object
{
public:
	StringObject(const char* str)
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
	~StringObject()
	{
		delete[] data;
		data = NULL;
	}
	void print()const
	{
		cout << data << "-->";
	}
	bool compare(Object* pb) const
	{
		StringObject* ps = dynamic_cast<StringObject*>(pb);
		assert(ps != NULL);
		int result;
		result = strcmp(data, ps->data);
		if (result >= 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
private:
	char* data;
};


//void main()
//{
//	/*
//	List myList;
//	for (int i = 1; i <= 5; ++i)
//	{
//		IntObject* pi = new IntObject(i);
//		myList.push_Back(pi);
//	}
//	myList.printList();
//
//	List YouList;
//	static const char* str[] = { "abc","def","ghi","jkl","mn"};
//	for (int j = 0; j < 5; ++j)
//	{
//		StringObject* ps = new StringObject(str[j]);
//		YouList.push_Back(ps);
//	}
//	YouList.printList();
//	*/
//	List myList;
//	IntObject* pi = new IntObject(3);
//	myList.insertOrder(pi);
//	pi = new IntObject(2);
//	myList.insertOrder(pi);
//	pi = new IntObject(5);
//	myList.insertOrder(pi);
//	pi = new IntObject(1);
//	myList.insertOrder(pi);
//	pi = new IntObject(4);
//	myList.insertOrder(pi);
//	myList.printList();
//
//
//	List youList;
//	static const char* str[] = { "xbc","def","ghi","akl","mn" };
//	for (int j = 0; j < 5; ++j)
//	{
//		StringObject* ps = new StringObject(str[j]);
//		youList.insertOrder(ps);
//	}
//	youList.printList();
//}