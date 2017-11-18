#include "stdafx.h"
#include "copy_controll.h"
using namespace std;

CanCopy::CanCopy(): CanCopy("", "")
{
}

CanCopy::CanCopy(string n, string d): name(n)
{
	data = new char[d.size() + 1];
	strcpy_s(data, d.size() + 1, d.c_str());
	cout << "����ɸ��ƶ���" << endl;
}

CanCopy::CanCopy(const CanCopy& cc)
{
	name = cc.name;
	size_t len = strlen(cc.data);
	data = new char[len + 1];
	strcpy_s(data, len + 1, cc.data);
	cout << "�ɸ��ƶ���ĸ��ƹ��캯��" << endl;
}

CanCopy& CanCopy::operator=(const CanCopy& cc)
{
	// ���Ƚ���ֵ����һ�ݣ������Ҹ�ֵ��ʱ����õ�
	string d = cc.data;
	// ɾ����ֵ�еľ����ݣ������ɾ���Ļ�������ڴ�й©����
	dispose();
	// Ȼ����ʱ���ݸ��Ƹ���ֵ
	name = cc.name;
	data = new char[d.size() + 1];
	strcpy_s(data, d.size() + 1, d.c_str());
	cout << "��ֵ�����" << endl;
	return *this;
}

void CanCopy::dispose()
{
	delete[]data;
}

CanCopy::~CanCopy()
{
	dispose();
	cout << "�����ɸ��ƶ���" << endl;
}

DefaultCopy::DefaultCopy(const DefaultCopy&) = default;

RefCount::RefCount(): RefCount("")
{
}

RefCount::RefCount(char str[])
{
	size_t len = strlen(str);
	data = new char[len + 1];
	strcpy_s(data, len + 1, str);
	count = new int(1);
	cout << "�������ü�������" << string(data) << endl;
}

RefCount::RefCount(const RefCount& rc)
{
	// ֱ�Ӹ��Ƴ�Ա��Ȼ��������ü���
	count = rc.count;
	data = rc.data;
	++*count;
	cout << "���ƹ���" << string(data) << "�����ü���+1�������ǣ�" << *count << endl;
}

RefCount& RefCount::operator=(const RefCount& rc)
{
	// �ȵ����Ҳ����ü���
	++*rc.count;
	cout << string(rc.data) << "���ü���+1��������:" << *rc.count << endl;
	// Ȼ��ݼ�������ü��������Ϊ�㣬�������ڴ�
	cout << string(data) << "���ü���-1��������:" << *count - 1 << endl;
	if (--*count == 0)
	{
		dispose();
	}
	// ����ұ߳�Աȫ��������ߣ��������Դ�������ֵ�����
	count = rc.count;
	data = rc.data;
	return *this;
}

void RefCount::dispose()
{
	// �����ڴ�
	cout << string(data) << "���ü���Ϊ�㣬�����ڴ�" << endl;
	delete count;
	delete[]data;
}

RefCount::~RefCount()
{
	cout << string(data) << "���ü���-1��������:" << *count - 1 << endl;
	if (--*count == 0)
	{
		dispose();
	}
}

CanSwap::CanSwap(): CanSwap(0, 0)
{
}

CanSwap::CanSwap(int v, int v2)
{
	value = v;
	pointer = new int(v2);
	cout << "����ɽ�������" << endl;
}

CanSwap::CanSwap(const CanSwap& cs)
{
	value = cs.value;
	pointer = new int(*cs.pointer);
}

CanSwap& CanSwap::operator=(CanSwap cs)
{
	/* ����ʹ�ø��Ʋ���������
	 * ������Ҳ�ĸ������н�����������ɺ��൱�ڸ�ֵ
	 * ����������Ҳั������Ϊ��������Զ�����
	 * ���ַ������ܱ����Ը�ֵ����
	 * ���������Ҫ���Ǹ�ֵ�������Ҳ�����ǰ�ֵ���ݵģ������Ҫ���帴�ƹ��캯��������������
	 */
	swap(*this, cs);
	cout << "ʹ�ø��Ʋ���������" << endl;
	return *this;
}

CanSwap::~CanSwap()
{
	delete pointer;
	cout << "������������ڴ�" << endl;
}

void swap(CanSwap& p1, CanSwap& p2)
{
	// ��Ϊ����ֻ��������Ա�����Ҷ�����ֱ�ӽ���������ֱ�ӵ��ñ�׼�⽻������
	swap(p1.value, p2.value);
	swap(p1.pointer, p2.pointer);
}

CanMove::CanMove(): CanMove("")
{
}

CanMove::CanMove(char str[])
{
	size_t len = strlen(str);
	data = new char[len + 1];
	strcpy_s(data, len + 1, str);
	cout << "������ƶ�����" << endl;
}

CanMove::CanMove(const CanMove& cm)
{
	size_t len = strlen(cm.data);
	data = new char[len + 1];
	strcpy_s(data, len + 1, cm.data);
	cout << "���ƶ�����ĸ��ƹ��캯��" << endl;
}

CanMove::CanMove(CanMove&& cm) noexcept: data(cm.data)
{
	cm.data = nullptr;
	cout << "���ƶ�������ƶ����캯��" << endl;
}

CanMove& CanMove::operator=(CanMove&& cm) noexcept
{
	// �������Ҹ�ֵ�����
	if (this != &cm)
	{
		delete[]data;
		data = cm.data;
		cm.data = nullptr;
	}
	cout << "���ƶ�������ƶ���ֵ����" << endl;
	return *this;
}

CanMove::~CanMove()
{
	delete[]data;
	cout << "���ƶ��������������" << endl;
}

void copy_controll()
{
	cout << "------�ɸ��ƶ�������------" << endl;
	CanCopy cp1("yitian", "666");
	CanCopy cp2 = cp1;
	CanCopy cp3(cp1);
	cout << "------���ƶ���������------" << endl;
	CanMove cm1("666");
	CanMove cm2 = cm1;
	CanMove cm3 = std::move(cm2);
	// 666��ʽ����Ϊ��ֵ����
	cm2 = "666";
	cout << "------���ü�����������------" << endl;
	RefCount rc1("666");
	RefCount rc2 = rc1;
	RefCount rc3("777");
	rc2 = rc3;
	rc1 = rc3;
	rc3 = rc3;
	cout << "------�ɽ������������------" << endl;
	CanSwap cs1(1, 1);
	CanSwap cs2(2, 2);
	cs1 = cs2;
	cout << "------�����ڴ�------" << endl;
}
