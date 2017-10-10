#include "stdafx.h"

using namespace std;

void if_statement()
{
	auto num = 10;
	auto isEven = 10 % 2 == 0;
	if (isEven)
	{
		cout << num << "��ż��" << endl;
	}
	else
	{
		cout << num << "������" << endl;
	}
}

void switch_statement()
{
	int mark = 75;
	switch (mark / 10)
	{
	case 6:
		cout << "����" << endl;
		break;
	case 7:
		cout << "����" << endl;
		break;
	case 8:
		cout << "����" << endl;
		break;
	case 9:
	case 10:
		cout << "����" << endl;
		break;
	default:
		cout << "������" << endl;
	}
}

void while_statement()
{
	int count = 10;
	while (count > 0)
	{
		count--;
	}
	cout << count << endl;
}

void for_statement()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << i << "\t";
	}
	cout << endl;
}

void foreach_statement()
{
	int array[] = {1,2,3,4,5};
	for (int i:array)
	{
		cout << i << "\t";
	}
	cout << endl;

	cout << "���Ҫ�޸�Ԫ��ֵ����Ҫʹ������" << endl;
	for (int& i:array)
	{
		i++;
	}
	cout << "�޸�֮�������" << endl;
	for (int i : array)
	{
		cout << i << "\t";
	}
	cout << endl;
}

void jump_statement()
{
	//break�����жϵ�ǰִ������
	int i;
	for (i = 0; i < 5; ++i)
	{
		if (i == 2)
		{
			break;
		}
	}
	cout << i << endl;
	//continue����������ǰִ�����̣�ֱ��ִ����һ��ѭ��
	for (i = 0; i < 5; ++i)
	{
		if (i == 2)
		{
			continue;
		}
	}
	cout << i << endl;

	//goto������������ת��������ò�Ҫʹ�ã����ںܶ�����Ҳû��goto����
	i = 0;
begin:i++;
	if (i < 3)
	{
		goto begin;
	}
	cout << i << endl;
}

void try_statement()
{
	try
	{
		throw runtime_error("����һ������ʱ����");
		cout << "�����������ִ��" << endl;
	}
	catch (runtime_error error)
	{
		cout << "�쳣��Ϣ:" << error.what() << endl;
	}catch (exception ex)
	{
		cout << "ͨ���쳣��Ϣ:" << ex.what() << endl;
	}
}

void statement()
{
	cout << "------------if���------------" << endl;
	if_statement();
	cout << "------------switch���------------" << endl;
	switch_statement();
	cout << "------------while���------------" << endl;
	while_statement();
	cout << "------------for���------------" << endl;
	for_statement();
	cout << "------------foreach���------------" << endl;
	foreach_statement();
	cout << "------------��ת���------------" << endl;
	jump_statement();
	cout << "------------try���------------" << endl;
	try_statement();
}
