#pragma once
#include "stdafx.h"

// class 类默认都是私有成员
class Person
{
private:
	static int people_count;
	//可变成员即使在const成员函数中也是可变的
	mutable bool error = false;
	// C++ 11 可以像Java那样在字段上初始化
	int id = 0;
	std::string name;


public:
	// 编译器生成默认构造函数
	Person() = default;

	Person(int id, std::string name)
	{
		this->id = id;
		this->name = name;
	}

	//委托构造函数，可以调用其他构造函数
	Person(std::string name): Person(0, name)
	{
	}

	//显式构造函数，只能用在单个参数构造函数上，阻止编译器执行隐式转换，同时该构造函数用于复制初始化
	//错误:Person p = 5;
	//正确:Person p(5);
	explicit Person(int id): Person(id, "")
	{
	}


	//常成员函数，不能修改类的成员，除非是可变成员
	void set_error(bool error) const
	{
		this->error = error;
		//id = 5;
	}

	// 友元函数可访问所有类成员，不受访问修饰符的影响
	friend void print_people_count();

	// 重载运算符
	friend std::ostream& operator<<(std::ostream& output, Person p)
	{
		output << "Person(" << p.id << ", " << p.name << ")";
		return output;
	}
};


inline void print_people_count()
{
	std::cout << "Person Cout:" << Person::people_count << std::endl;
}

// struct 类默认都是公有成员
struct Contact
{
	int id = 0;
	std::string name;

	Contact() = default;

	Contact(int id, std::string name)
	{
		this->id = id;
		this->name = name;
	}
};

void oop_show_case()
{
	Person p1;
	Person p2(5, "yitian");
	std::cout << "p2:" << p2 << std::endl;
}
