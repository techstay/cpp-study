#include "stdafx.h"
using namespace std;

void arithmetic_operator()
{
	auto result = 0.0;
	result = 1 + 1;
	result = 1 - 1;
	result = 1 * 4;
	result = 4 / 2;
	result = 5 % 3;
	result = -3;
	result = +4;
}


void logical_operator()
{
	//逻辑运算符
	bool result;
	result = true && false;
	result = true || false;
	result = !true;


	//关系运算符
	result = 1 <= 2;
	result = 1 >= 2;
	result = 1 == 2;
	result = 1 != 2;
	result = 1 > 2;
	result = 1 < 2;
}

void assignment_opeartor()
{
	int i = 5;
	//列表初始化，C++ 11新增
	int j = {3};
	int list[] = {1,2,3};
}

void condition_operator()
{
	int num = 10;
	bool isEven = num % 2 == 0 ? true : false;
}

void bitwise_operator()
{
	int result;
	//按位取反
	result = ~1;
	//按位与
	result = 1 & 2;
	//按位或
	result = 1 | 2;
	//按位异或
	result = 1 ^ 2;
	//左移
	result = 8 << 2;
	//右移
	result = 8 >> 2;
}

void sizeof_operator()
{
	int array[] = {1,2,3,4};
	size_t size = sizeof(array);
	cout << size << endl;
}

void comma_operator()
{
	//逗号表达式的值是最后一个值
	auto i = (3 , 4);
	cout << i << endl;
}

void operators()
{
	cout << "------------算术运算符------------" << endl;
	arithmetic_operator();
	cout << "------------逻辑和关系运算符------------" << endl;
	logical_operator();
	cout << "------------赋值运算符------------" << endl;
	assignment_opeartor();
	cout << "------------条件运算符------------" << endl;
	condition_operator();
	cout << "------------位运算符------------" << endl;
	bitwise_operator();
	cout << "------------sizeof运算符------------" << endl;
	sizeof_operator();
	cout << "------------逗号运算符------------" << endl;
	comma_operator();
}
