// OOP.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "class.h"
#include "copy_controll.h"
#include "operator_overloading.h"
#include "oop.h"
using namespace std;

int main()
{
	cout << "---------类声明----------" << endl;
	classes();
	cout << "---------复制控制----------" << endl;
	copy_controll();
	cout << boolalpha;
	cout << "---------运算符重载----------" << endl;
	operator_overloading();
	cout << "---------OOP----------" << endl;
	oop();
	return 0;
}
