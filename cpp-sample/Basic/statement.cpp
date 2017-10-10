#include "stdafx.h"

using namespace std;

void if_statement()
{
	auto num = 10;
	auto isEven = 10 % 2 == 0;
	if (isEven)
	{
		cout << num << "是偶数" << endl;
	}
	else
	{
		cout << num << "是奇数" << endl;
	}
}

void switch_statement()
{
	int mark = 75;
	switch (mark / 10)
	{
	case 6:
		cout << "及格" << endl;
		break;
	case 7:
		cout << "良好" << endl;
		break;
	case 8:
		cout << "优秀" << endl;
		break;
	case 9:
	case 10:
		cout << "极好" << endl;
		break;
	default:
		cout << "不及格" << endl;
	}
}

void while_statement()
{
	int count = 10;
	while (count > 0)
	{
		count--;
	}
	cout << count << endl;
}

void for_statement()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << i << "\t";
	}
	cout << endl;
}

void foreach_statement()
{
	int array[] = {1,2,3,4,5};
	for (int i:array)
	{
		cout << i << "\t";
	}
	cout << endl;

	cout << "如果要修改元素值，需要使用引用" << endl;
	for (int& i:array)
	{
		i++;
	}
	cout << "修改之后的数组" << endl;
	for (int i : array)
	{
		cout << i << "\t";
	}
	cout << endl;
}

void jump_statement()
{
	//break语句会中断当前执行流程
	int i;
	for (i = 0; i < 5; ++i)
	{
		if (i == 2)
		{
			break;
		}
	}
	cout << i << endl;
	//continue语句会跳过当前执行流程，直接执行下一次循环
	for (i = 0; i < 5; ++i)
	{
		if (i == 2)
		{
			continue;
		}
	}
	cout << i << endl;

	//goto语句可以随意跳转，所以最好不要使用，现在很多语言也没有goto功能
	i = 0;
begin:i++;
	if (i < 3)
	{
		goto begin;
	}
	cout << i << endl;
}

void try_statement()
{
	try
	{
		throw runtime_error("这是一个运行时错误");
		cout << "假如程序正常执行" << endl;
	}
	catch (runtime_error error)
	{
		cout << "异常信息:" << error.what() << endl;
	}catch (exception ex)
	{
		cout << "通用异常信息:" << ex.what() << endl;
	}
}

void statement()
{
	cout << "------------if语句------------" << endl;
	if_statement();
	cout << "------------switch语句------------" << endl;
	switch_statement();
	cout << "------------while语句------------" << endl;
	while_statement();
	cout << "------------for语句------------" << endl;
	for_statement();
	cout << "------------foreach语句------------" << endl;
	foreach_statement();
	cout << "------------跳转语句------------" << endl;
	jump_statement();
	cout << "------------try语句------------" << endl;
	try_statement();
}
