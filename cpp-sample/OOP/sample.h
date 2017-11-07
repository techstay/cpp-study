#pragma once
#include "stdafx.h"

// class ��Ĭ�϶���˽�г�Ա
class Person
{
private:
	static int people_count;
	//�ɱ��Ա��ʹ��const��Ա������Ҳ�ǿɱ��
	mutable bool error = false;
	// C++ 11 ������Java�������ֶ��ϳ�ʼ��
	int id = 0;
	std::string name;


public:
	// ����������Ĭ�Ϲ��캯��
	Person() = default;

	Person(int id, std::string name)
	{
		this->id = id;
		this->name = name;
	}

	//ί�й��캯�������Ե����������캯��
	Person(std::string name): Person(0, name)
	{
	}

	//��ʽ���캯����ֻ�����ڵ����������캯���ϣ���ֹ������ִ����ʽת����ͬʱ�ù��캯�����ڸ��Ƴ�ʼ��
	//����:Person p = 5;
	//��ȷ:Person p(5);
	explicit Person(int id): Person(id, "")
	{
	}


	//����Ա�����������޸���ĳ�Ա�������ǿɱ��Ա
	void set_error(bool error) const
	{
		this->error = error;
		//id = 5;
	}

	// ��Ԫ�����ɷ����������Ա�����ܷ������η���Ӱ��
	friend void print_people_count();

	// ���������
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

// struct ��Ĭ�϶��ǹ��г�Ա
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
