#include "stdafx.h"
using namespace std;

void smart_pointers()
{
	// 定义一个空的共享智能指针
	shared_ptr<string> sp;
	// 向指针赋值
	sp = make_shared<string>("hello");
	if (sp && sp->empty())
	{
	}
	else
	{
		cout << *sp << endl;
	}
	// 获取智能指针中保存的裸指针，一般不应该用
	string* str_p = sp.get();
	// 复制智能指针，引用计数加一
	auto sp2 = sp;
	// 判断当前智能指针是否只有一个用例
	bool is_unique = sp.unique();
	cout << "is_unique:" << is_unique << endl;;
	// 获取所有的共享智能指针数量，主要用于调试
	int count = sp.use_count();
	cout << "count:" << count << endl;
	// 有时候内存的分配和释放不是使用new和delete，就需要设置删除器
	// 当释放内存的时候会调用删除器来释放
	auto assign = [] { return new int(5); };
	auto release = [](int* p) { delete p; };
	shared_ptr<int> sp3(assign(), release);

	// unique_ptr指针的对象是单独的，不能共享
	unique_ptr<int> up = make_unique<int>(5);
	// 返回指针并将智能指针置空
	int* pointer = up.release();
	auto up3 = unique_ptr<int>(pointer);
	// 释放相应对象
	up3.reset();
	// 将智能指针和新的指针绑定
	up3.reset(new int(5));


	// 弱智能指针，不会增加引用计数，使用若智能指针的时候有可能实际对象已被释放
	weak_ptr<int> wp = make_shared<int>(5);
	// 返回引用计数
	int use_count = wp.use_count();
	// 判断实际对象是否存在
	bool is_expired = wp.expired();
	// 若实际对象存在，返回该对象，否则返回空智能指针
	shared_ptr<int> actual_ptr = wp.lock();
}

void manual_memory_controll()
{
	// 动态分配一块内存
	int* p1 = new int(5);
	cout << *p1 << endl;
	// 清空内存
	delete p1;
	// 最好在清空后将指针置零，防止引用未定义内容
	p1 = nullptr;

	// 假如内存不够分配，会跑出bad_alloc异常，这可以向new操作符传递参数来避免
	// 这时候如果分配内存失败，会返回空指针
	int* p2 = new(nothrow) int(100);
}

/*
 * 将分配内存和初始化分离的分配器
 */
void allocators()
{
	const int N = 10;
	// 定义一个可以分配string的allocator
	allocator<string> alloc;
	// 分配可保存指定数量数据的连续内存，这些内存是原始内存，还未进行初始化，因此什么也不能做
	allocator<string>::pointer pointer = alloc.allocate(N);
	// 为上面分配的原始内存初始化数据
	for (int i = 0; i < N; ++i)
	{
		alloc.construct(pointer + i, to_string(i));
	}
	// 访问内存中的每个数据
	for (int i = 0; i < N; ++i)
	{
		cout << pointer[i] << ", ";
	}
	cout << endl;
	// 释放每个内存空间的数据
	for (int i = 0; i < N; ++i)
	{
		alloc.destroy(pointer + i);
	}
	// 释放整个内存
	alloc.deallocate(pointer, N);
}
