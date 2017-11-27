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
	// �麯��
	virtual void do_it();
	// ���麯��
	virtual void do_something() = 0;
	// ����������ö���Ϊ�麯�����Ա����������඼����ȷ������Դ
	virtual ~BaseClass() = default;
};


class DeriveClass : public BaseClass
{
public:
	// ��using��ʽ�ı��Ա�ķ���Ȩ�ޣ�����������������Է��ʵĳ�Ա
	using BaseClass::protected_field;
	// override�ؼ��֣������ú�����д�˻�����麯��
	void do_something() override;
};

// C++ 11�����������޷����̳�
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
