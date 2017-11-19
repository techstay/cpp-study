#pragma once
#include "stdafx.h"

class MyClass
{
	int val;

public:
	MyClass() : val(0)
	{
	}

	MyClass(int v) : val(v)
	{
	}

	// 运算符重载


	// 对于流运算符，由于无法在标准库上添加成员函数，所以只能定义成友元函数重载
	// 对于加法等运算符，希望可以自动进行隐式转换，所以也定义成友元函数重载
	friend MyClass operator+(const MyClass& a, const MyClass& b);
	MyClass& operator+=(const MyClass& b);
	friend std::ostream& operator<<(std::ostream& out, const MyClass& obj);
	friend std::istream& operator>>(std::istream& in, MyClass& obj);
	// 因为具有对称性的运算符定义为友元函数更加合适
	friend bool operator==(const MyClass& a, const MyClass& b);
	// 不等运算符应该调用相等运算符，而不是重新实现一次
	friend bool operator!=(const MyClass& a, const MyClass& b);
	friend bool operator<(const MyClass& a, const MyClass& b);
	friend bool operator>(const MyClass& a, const MyClass& b);
	friend bool operator<=(const MyClass& a, const MyClass& b);
	friend bool operator>=(const MyClass& a, const MyClass& b);
	// 前置递增递减运算符
	// 前置运算符返回引用
	MyClass& operator++();
	MyClass& operator--();
	// 后置递增递减运算符需要使用一个形式参数和前置运算符区分
	// 后置运算符返回值
	MyClass operator--(int);
	MyClass operator++(int);
	// 函数调用运算符
	void operator()();
	void operator()(int n);
	// 类型转换运算符，不需要返回类型，通常定义为const函数
	operator int() const;
	// 显式类型转换操作符，不会用于隐式转换
	explicit operator bool() const;
};

class MyList
{
	std::vector<int> list;
public:
	MyList(): list()
	{
	}

	// 赋值运算符应该定义为成员函数
	// 赋值运算符一般需要释放当前的内存空间
	// 初始化列表赋值运算符
	MyList& operator=(std::initializer_list<int> list);
	// 下标运算符必须定义为成员函数
	int& operator[](std::size_t n);
	// 最好同时定义下标运算符的常量版本，返回元素的常量引用
	const int& operator[](std::size_t n) const;
};

void operator_overloading();
