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
	cout << "构造可复制对象" << endl;
}

CanCopy::CanCopy(const CanCopy& cc)
{
	name = cc.name;
	size_t len = strlen(cc.data);
	data = new char[len + 1];
	strcpy_s(data, len + 1, cc.data);
	cout << "可复制对象的复制构造函数" << endl;
}

CanCopy& CanCopy::operator=(const CanCopy& cc)
{
	// 首先将右值复制一份，在自我赋值的时候会用到
	string d = cc.data;
	// 删除左值中的旧数据，如果不删除的话会出现内存泄漏问题
	dispose();
	// 然后将临时数据复制给左值
	name = cc.name;
	data = new char[d.size() + 1];
	strcpy_s(data, d.size() + 1, d.c_str());
	cout << "赋值运算符" << endl;
	return *this;
}

void CanCopy::dispose()
{
	delete[]data;
}

CanCopy::~CanCopy()
{
	dispose();
	cout << "析构可复制对象" << endl;
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
	cout << "构造引用计数对象" << string(data) << endl;
}

RefCount::RefCount(const RefCount& rc)
{
	// 直接复制成员，然后递增引用计数
	count = rc.count;
	data = rc.data;
	++*count;
	cout << "复制构造" << string(data) << "，引用计数+1，现在是：" << *count << endl;
}

RefCount& RefCount::operator=(const RefCount& rc)
{
	// 先递增右侧引用计数
	++*rc.count;
	cout << string(rc.data) << "引用计数+1，现在是:" << *rc.count << endl;
	// 然后递减左侧引用计数，如果为零，则清理内存
	cout << string(data) << "引用计数-1，现在是:" << *count - 1 << endl;
	if (--*count == 0)
	{
		dispose();
	}
	// 最后将右边成员全部赋给左边，这样可以处理自身赋值的情况
	count = rc.count;
	data = rc.data;
	return *this;
}

void RefCount::dispose()
{
	// 清理内存
	cout << string(data) << "引用计数为零，清理内存" << endl;
	delete count;
	delete[]data;
}

RefCount::~RefCount()
{
	cout << string(data) << "引用计数-1，现在是:" << *count - 1 << endl;
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
	cout << "构造可交换对象" << endl;
}

CanSwap::CanSwap(const CanSwap& cs)
{
	value = cs.value;
	pointer = new int(*cs.pointer);
}

CanSwap& CanSwap::operator=(CanSwap cs)
{
	/* 这里使用复制并交换技术
	 * 左侧与右侧的副本进行交换，交换完成后，相当于赋值
	 * 而交换后的右侧副本会因为作用域而自动销毁
	 * 这种方法还能避免自赋值问题
	 * 这个方法的要点是赋值操作符右侧参数是按值传递的，因此需要定义复制构造函数才能正常工作
	 */
	swap(*this, cs);
	cout << "使用复制并交换技术" << endl;
	return *this;
}

CanSwap::~CanSwap()
{
	delete pointer;
	cout << "清除交换对象内存" << endl;
}

void swap(CanSwap& p1, CanSwap& p2)
{
	// 因为这里只有两个成员，而且都可以直接交换，所以直接调用标准库交换函数
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
	cout << "构造可移动对象" << endl;
}

CanMove::CanMove(const CanMove& cm)
{
	size_t len = strlen(cm.data);
	data = new char[len + 1];
	strcpy_s(data, len + 1, cm.data);
	cout << "可移动对象的复制构造函数" << endl;
}

CanMove::CanMove(CanMove&& cm) noexcept: data(cm.data)
{
	cm.data = nullptr;
	cout << "可移动对象的移动构造函数" << endl;
}

CanMove& CanMove::operator=(CanMove&& cm) noexcept
{
	// 处理自我赋值的情况
	if (this != &cm)
	{
		delete[]data;
		data = cm.data;
		cm.data = nullptr;
	}
	cout << "可移动对象的移动赋值操作" << endl;
	return *this;
}

CanMove::~CanMove()
{
	delete[]data;
	cout << "可移动对象的析构操作" << endl;
}

void copy_controll()
{
	cout << "------可复制对象例子------" << endl;
	CanCopy cp1("yitian", "666");
	CanCopy cp2 = cp1;
	CanCopy cp3(cp1);
	cout << "------可移动对象例子------" << endl;
	CanMove cm1("666");
	CanMove cm2 = cm1;
	CanMove cm3 = std::move(cm2);
	// 666隐式构造为右值对象
	cm2 = "666";
	cout << "------引用计数对象例子------" << endl;
	RefCount rc1("666");
	RefCount rc2 = rc1;
	RefCount rc3("777");
	rc2 = rc3;
	rc1 = rc3;
	rc3 = rc3;
	cout << "------可交换对象的例子------" << endl;
	CanSwap cs1(1, 1);
	CanSwap cs2(2, 2);
	cs1 = cs2;
	cout << "------清理内存------" << endl;
}
