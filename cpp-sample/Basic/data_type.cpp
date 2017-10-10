#include "stdafx.h"

using namespace std;

void basic_data_type()
{
	//����
	bool b = true;
	char c = 'c';
	wchar_t wc = 'c';
	char16_t c16 = 'c';
	char32_t c32 = 'c';
	short s = 600;
	int i = 1000;
	long l = 1000L;
	long long ll = 1000LL;

	//������
	float f = 3.5F;
	double d = 3.5;
	long double ld = 3.1415L;

	//�з��ź��޷���
	signed int si = -1000;
	unsigned int ui = 1000U;

	//�ַ����ַ���������
	char cc = 'c';
	char str[] = "abc";
	char long_string[] = "This is a long line "
		"and next line";

	char unicode[] = u8"�ַ���";
}

void pointer()
{
	int d1 = 5, d2 = 6;
	//��������ָ��
	int *p1, *p2;
	//Ϊָ�븳ֵ
	p1 = &d1;
	p2 = &d2;
	//ָ��ָ����Ӧ����
	cout << "d1=" << d1 << ",p1=" << *p1 << endl;
	//�޸�ָ��ָ��Ķ����ֱ�Ӹı�����ֵ
	*p1 = 100;
	cout << "d1=" << d1 << ",p1=" << *p1 << endl;

	//���ָ��
	p2 = nullptr;
	cout << "d1=" << d1 << ",p1=" << *p1 << endl;
}

void reference()
{
	int d1 = 5;
	//d2��d1������
	int& d2 = d1;
	cout << "d1=" << d1 << ",d2=" << d2 << endl;

	//�޸�����Ҳ���޸�ԭ����
	d2 = 100;
	cout << "d1=" << d1 << ",d2=" << d2 << endl;
}

void compound_type()
{
	//���������ͱ��������һ��
	int *p, d;
	//ָ���ָ��
	int** pp = &p;
	//ָ�������
	int*& r = p;
}

void const_variable()
{
	//���ó���
	int i = 5;
	const int& r = i;
	i = 10;
	//r = 10;

	int j = 100;
	//constָ��
	int*const cp = &i;
	//����ͨ��ָ���޸Ķ����ֵ
	*cp = 10;
	//�޷��޸�ָ��ָ��Ķ���
	//cp = &j;

	const int* p = &i;
	//�����޸�ָ��ָ��Ķ���
	p = &j;
	//�޷�ͨ��ָ���޸�ֵ
	//*p = 200;

	//���Ƕ���const���ǵײ�const
	const int*const ccp = &i;

	//�������ʽ
	constexpr int MAX_COUNT = 100;
	constexpr int MIN_COUNT = -MAX_COUNT;
	//i���ǳ�������������Ĵ��벻�ܱ���
	//constexpr int VARIABLE_COUNT = i;
}

void data_type()
{
	cout << "------------������������------------" << endl;
	basic_data_type();
	cout << "------------ָ��------------" << endl;
	pointer();
	cout << "------------����------------" << endl;
	reference();
	cout << "------------��������------------" << endl;
	compound_type();
	cout << "------------����------------" << endl;
	const_variable();
}

