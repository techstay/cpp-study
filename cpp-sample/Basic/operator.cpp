#include "stdafx.h"
using namespace std;

void arithmetic_operator()
{
	auto result = 0.0;
	result = 1 + 1;
	result = 1 - 1;
	result = 1 * 4;
	result = 4 / 2;
	result = 5 % 3;
	result = -3;
	result = +4;
}


void logical_operator()
{
	//�߼������
	bool result;
	result = true && false;
	result = true || false;
	result = !true;


	//��ϵ�����
	result = 1 <= 2;
	result = 1 >= 2;
	result = 1 == 2;
	result = 1 != 2;
	result = 1 > 2;
	result = 1 < 2;
}

void assignment_opeartor()
{
	int i = 5;
	//�б��ʼ����C++ 11����
	int j = {3};
	int list[] = {1,2,3};
}

void condition_operator()
{
	int num = 10;
	bool isEven = num % 2 == 0 ? true : false;
}

void bitwise_operator()
{
	int result;
	//��λȡ��
	result = ~1;
	//��λ��
	result = 1 & 2;
	//��λ��
	result = 1 | 2;
	//��λ���
	result = 1 ^ 2;
	//����
	result = 8 << 2;
	//����
	result = 8 >> 2;
}

void sizeof_operator()
{
	int array[] = {1,2,3,4};
	size_t size = sizeof(array);
	cout << size << endl;
}

void comma_operator()
{
	//���ű��ʽ��ֵ�����һ��ֵ
	auto i = (3 , 4);
	cout << i << endl;
}

void operators()
{
	cout << "------------���������------------" << endl;
	arithmetic_operator();
	cout << "------------�߼��͹�ϵ�����------------" << endl;
	logical_operator();
	cout << "------------��ֵ�����------------" << endl;
	assignment_opeartor();
	cout << "------------���������------------" << endl;
	condition_operator();
	cout << "------------λ�����------------" << endl;
	bitwise_operator();
	cout << "------------sizeof�����------------" << endl;
	sizeof_operator();
	cout << "------------���������------------" << endl;
	comma_operator();
}
