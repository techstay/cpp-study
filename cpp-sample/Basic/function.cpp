#include "stdafx.h"

using namespace std;


//无参函数
void fun1()
{
}

//默认参数必须放在最后
//默认参数最好放在函数声明中，函数声明和定义不能同时存在默认参数
void fun2(int a, int b = 0)
{
}

//内联函数，应该定义在头文件中
inline int add(int a, int b)
{
	return a + b;
}

//重载函数，函数名相同参数列表不同
void fun3()
{
}

void fun3(int a)
{
}

void fun3(int a, std::string b)
{
}

//指向函数的指针
void pointerToFuntion()
{
	typedef void (*fun)();
	fun f1 = &fun1;
	(*f1)();

	//指针置零
	f1 = nullptr;
}

//递归函数
int gcd(int a, int b)
{
	int dividend, divisor, quotient, remainder;
	if (a < b)
	{
		dividend = b;
		divisor = a;
	}
	else
	{
		dividend = a;
		divisor = b;
	}
	quotient = dividend / divisor;
	remainder = dividend % divisor;
	if (remainder == 0)
	{
		return divisor;
	}
	else
	{
		return gcd(divisor, remainder);
	}
}

void functions()
{
	cout << "------------递归求最大公约数------------" << endl;
	cout << "24和16的最大公约数是" << gcd(24, 16) << endl;
}
