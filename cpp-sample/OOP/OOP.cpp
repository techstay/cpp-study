// OOP.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "sample.h"
#include "copy_controll.h"
#include "operator_overloading.h"
using namespace std;

int main()
{
	oop_show_case();
	cout << "---------复制控制----------" << endl;
	copy_controll();
	cout << boolalpha;
	cout << "---------运算符重载----------" << endl;
	operator_overloading();
	return 0;
}
