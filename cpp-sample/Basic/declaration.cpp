#include "stdafx.h"
using namespace std;

int global_count = 5;

void declare_and_define()
{
	//�������
	int i = 5;


	cout << global_count << endl;
	if (true)
	{
		int global_count = 5;
		cout << "ͬ���ֲ���������ȫ�ֱ���:" << global_count << endl;
		cout << "ʹ��ȫ�ֱ���:" << ::global_count << endl;
	}

	//���峣��
	const int const_count = 5;
}

void define_variables()
{
	//�������
	int a;
	//���岢��ʼ��
	int b = 1;
	//ͬʱ����������
	int c = 5, d = 6;
	//C++ 11 �����ԣ��б��ʼ��
	int e{3};

	//���ܱ���
	//short s{3.1415};
	short s = 3.1415;
}

void type_defination()
{
	//typedef�ؼ���
	typedef int integer;
	integer i = 5;
	typedef int* pointer;
	pointer p1 = &i, p2 = &i;
	cout << "*p1=" << *p1 << ", *p2=" << *p2 << endl;

	//��������
	using charater = char;
	charater c = 'c';

	//auto�ؼ���
	auto number = 100;//number��int
	auto pnumber = &number;//pnumber��int*
	auto ca = 'a', cb = 'b';

	//���Զ���const�������ײ�const
	const int cn = 100;
	const int* pn = &cn;
	auto cn2 = cn;
	auto pn2 = pn;

	//decltype�ؼ���
	decltype(5 + 5) n1;//int
	decltype(5 + 5.0) n2;//double
	decltype((n2)) n3 = n2;//int&
}

void declare()
{
	cout << "------------���������------------" << endl;
	declare_and_define();
	define_variables();
	cout << "------------��������------------" << std::endl;
	type_defination();
}
