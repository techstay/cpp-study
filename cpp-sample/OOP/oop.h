#pragma once
#include "stdafx.h"

class BaseClass
{
private:
	int private_field;
protected:
	int protected_field;
public:

	BaseClass(int pri = 0, int pro = 0, int pub = 0): private_field(pri), protected_field(pro), public_field(pub)
	{
	}

	int public_field;
	// 虚函数
	virtual void do_it();
	// 纯虚函数
	virtual void do_something() = 0;
	// 析构函数最好定义为虚函数，以便所有派生类都能正确清理资源
	virtual ~BaseClass() = default;
};


class DeriveClass : public BaseClass
{
public:
	// 用using显式改变成员的访问权限，仅适用于派生类可以访问的成员
	using BaseClass::protected_field;
	// override关键字，表明该函数重写了基类的虚函数
	void do_something() override;
};

// C++ 11新增，该类无法被继承
class NoDerive final
{
};

class Shape
{
public:
	virtual double getArea() = 0;
	virtual std::string getInfo() = 0;

	virtual ~Shape()
	{
	}
};

class Rectangle : public Shape
{
	double a, b;
public:
	Rectangle(double a = 0, double b = 0): a(a), b(b)
	{
	}

	double getArea() override;
	std::string getInfo() override;
};

class Square : public Rectangle
{
public :
	Square(double a): Rectangle(a, a)
	{
	}
	std::string getInfo() override;
};

class Triangle : public Shape
{
	double a, b, c;
public:
	Triangle(double a, double b, double c): a(a), b(b), c(c)
	{
	}

	double getArea() override;
	std::string getInfo() override;
};

class Circle : public Shape
{
	double r;
public:
	Circle(double a): r(a)
	{
	}

	double getArea() override;
	std::string getInfo() override;
};

void oop();
