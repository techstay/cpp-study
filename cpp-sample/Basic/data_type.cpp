#include "stdafx.h"

using namespace std;

void basic_data_type()
{
	//整型
	bool b = true;
	char c = 'c';
	wchar_t wc = 'c';
	char16_t c16 = 'c';
	char32_t c32 = 'c';
	short s = 600;
	int i = 1000;
	long l = 1000L;
	long long ll = 1000LL;

	//浮点型
	float f = 3.5F;
	double d = 3.5;
	long double ld = 3.1415L;

	//有符号和无符号
	signed int si = -1000;
	unsigned int ui = 1000U;

	//字符和字符型字面量
	char cc = 'c';
	char str[] = "abc";
	char long_string[] = "This is a long line "
		"and next line";

	char unicode[] = u8"字符串";
}

void pointer()
{
	int d1 = 5, d2 = 6;
	//定义两个指针
	int *p1, *p2;
	//为指针赋值
	p1 = &d1;
	p2 = &d2;
	//指针指向相应对象
	cout << "d1=" << d1 << ",p1=" << *p1 << endl;
	//修改指针指向的对象会直接改变它的值
	*p1 = 100;
	cout << "d1=" << d1 << ",p1=" << *p1 << endl;

	//清空指针
	p2 = nullptr;
	cout << "d1=" << d1 << ",p1=" << *p1 << endl;
}

void reference()
{
	int d1 = 5;
	//d2是d1的引用
	int& d2 = d1;
	cout << "d1=" << d1 << ",d2=" << d2 << endl;

	//修改引用也会修改原变量
	d2 = 100;
	cout << "d1=" << d1 << ",d2=" << d2 << endl;
}

void compound_type()
{
	//类型声明和变量组合在一起
	int *p, d;
	//指针的指针
	int** pp = &p;
	//指针的引用
	int*& r = p;
}

void const_variable()
{
	//引用常量
	int i = 5;
	const int& r = i;
	i = 10;
	//r = 10;

	int j = 100;
	//const指针
	int*const cp = &i;
	//可以通过指针修改对象的值
	*cp = 10;
	//无法修改指针指向的对象
	//cp = &j;

	const int* p = &i;
	//可以修改指针指向的对象
	p = &j;
	//无法通过指针修改值
	//*p = 200;

	//既是顶层const又是底层const
	const int*const ccp = &i;

	//常量表达式
	constexpr int MAX_COUNT = 100;
	constexpr int MIN_COUNT = -MAX_COUNT;
	//i不是常量，所以下面的代码不能编译
	//constexpr int VARIABLE_COUNT = i;
}

void data_type()
{
	cout << "------------基本数据类型------------" << endl;
	basic_data_type();
	cout << "------------指针------------" << endl;
	pointer();
	cout << "------------引用------------" << endl;
	reference();
	cout << "------------复合类型------------" << endl;
	compound_type();
	cout << "------------常量------------" << endl;
	const_variable();
}

