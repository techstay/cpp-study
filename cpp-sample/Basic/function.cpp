#include "stdafx.h"

using namespace std;


//�޲κ���
void fun1()
{
}

//Ĭ�ϲ�������������
//Ĭ�ϲ�����÷��ں��������У����������Ͷ��岻��ͬʱ����Ĭ�ϲ���
void fun2(int a, int b = 0)
{
}

//����������Ӧ�ö�����ͷ�ļ���
inline int add(int a, int b)
{
	return a + b;
}

//���غ�������������ͬ�����б�ͬ
void fun3()
{
}

void fun3(int a)
{
}

void fun3(int a, std::string b)
{
}

//ָ������ָ��
void pointerToFuntion()
{
	typedef void (*fun)();
	fun f1 = &fun1;
	(*f1)();

	//ָ������
	f1 = nullptr;
}

//�ݹ麯��
int gcd(int a, int b)
{
	int dividend, divisor, quotient, remainder;
	if (a < b)
	{
		dividend = b;
		divisor = a;
	}
	else
	{
		dividend = a;
		divisor = b;
	}
	quotient = dividend / divisor;
	remainder = dividend % divisor;
	if (remainder == 0)
	{
		return divisor;
	}
	else
	{
		return gcd(divisor, remainder);
	}
}

void functions()
{
	cout << "------------�ݹ������Լ��------------" << endl;
	cout << "24��16�����Լ����" << gcd(24, 16) << endl;
}
