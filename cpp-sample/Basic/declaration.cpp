#include "stdafx.h"
using namespace std;

int global_count = 5;

void declare_and_define()
{
	//定义变量
	int i = 5;


	cout << global_count << endl;
	if (true)
	{
		int global_count = 5;
		cout << "同名局部变量覆盖全局变量:" << global_count << endl;
		cout << "使用全局变量:" << ::global_count << endl;
	}

	//定义常量
	const int const_count = 5;
}

void define_variables()
{
	//定义变量
	int a;
	//定义并初始化
	int b = 1;
	//同时定义多个变量
	int c = 5, d = 6;
	//C++ 11 新特性：列表初始化
	int e{3};

	//不能编译
	//short s{3.1415};
	short s = 3.1415;
}

void type_defination()
{
	//typedef关键字
	typedef int integer;
	integer i = 5;
	typedef int* pointer;
	pointer p1 = &i, p2 = &i;
	cout << "*p1=" << *p1 << ", *p2=" << *p2 << endl;

	//别名声明
	using charater = char;
	charater c = 'c';

	//auto关键字
	auto number = 100;//number是int
	auto pnumber = &number;//pnumber是int*
	auto ca = 'a', cb = 'b';

	//忽略顶层const，保留底层const
	const int cn = 100;
	const int* pn = &cn;
	auto cn2 = cn;
	auto pn2 = pn;

	//decltype关键字
	decltype(5 + 5) n1;//int
	decltype(5 + 5.0) n2;//double
	decltype((n2)) n3 = n2;//int&
}

void declare()
{
	cout << "------------定义和声明------------" << endl;
	declare_and_define();
	define_variables();
	cout << "------------类型声明------------" << std::endl;
	type_defination();
}
