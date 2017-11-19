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

	// ���������


	// ������������������޷��ڱ�׼������ӳ�Ա����������ֻ�ܶ������Ԫ��������
	// ���ڼӷ����������ϣ�������Զ�������ʽת��������Ҳ�������Ԫ��������
	friend MyClass operator+(const MyClass& a, const MyClass& b);
	MyClass& operator+=(const MyClass& b);
	friend std::ostream& operator<<(std::ostream& out, const MyClass& obj);
	friend std::istream& operator>>(std::istream& in, MyClass& obj);
	// ��Ϊ���жԳ��Ե����������Ϊ��Ԫ�������Ӻ���
	friend bool operator==(const MyClass& a, const MyClass& b);
	// ���������Ӧ�õ�����������������������ʵ��һ��
	friend bool operator!=(const MyClass& a, const MyClass& b);
	friend bool operator<(const MyClass& a, const MyClass& b);
	friend bool operator>(const MyClass& a, const MyClass& b);
	friend bool operator<=(const MyClass& a, const MyClass& b);
	friend bool operator>=(const MyClass& a, const MyClass& b);
	// ǰ�õ����ݼ������
	// ǰ���������������
	MyClass& operator++();
	MyClass& operator--();
	// ���õ����ݼ��������Ҫʹ��һ����ʽ������ǰ�����������
	// �������������ֵ
	MyClass operator--(int);
	MyClass operator++(int);
	// �������������
	void operator()();
	void operator()(int n);
	// ����ת�������������Ҫ�������ͣ�ͨ������Ϊconst����
	operator int() const;
	// ��ʽ����ת��������������������ʽת��
	explicit operator bool() const;
};

class MyList
{
	std::vector<int> list;
public:
	MyList(): list()
	{
	}

	// ��ֵ�����Ӧ�ö���Ϊ��Ա����
	// ��ֵ�����һ����Ҫ�ͷŵ�ǰ���ڴ�ռ�
	// ��ʼ���б�ֵ�����
	MyList& operator=(std::initializer_list<int> list);
	// �±���������붨��Ϊ��Ա����
	int& operator[](std::size_t n);
	// ���ͬʱ�����±�������ĳ����汾������Ԫ�صĳ�������
	const int& operator[](std::size_t n) const;
};

void operator_overloading();
