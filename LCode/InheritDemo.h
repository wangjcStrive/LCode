#pragma once
#include "solutions.h"

class BaseInheritTest 
{
public:
	// func1不是virtual的，所以不具有多态的性质，即当一个父类指针指向的是一个子类的对象，通过该指针
	// 访问func1的时候，实际上调用的是父类的func1
	void func1()
	{
		cout << "base func1" << endl;
	}
	virtual void func2()
	{
		cout << "base func2" << endl;
	}
};

class DeriveInheritTest :public BaseInheritTest
{
public:
	void func1() { cout << "derive func1" << endl; }
	void func2() { cout << "derive func2" << endl; }
};
