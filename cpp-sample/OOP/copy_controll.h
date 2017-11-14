#pragma once
#include "stdafx.h"

class CanCopy
{
	std::string name;
	char* data;
public:
	CanCopy();
	CanCopy(std::string, std::string);
	// 复制构造函数，刚才忘了定义，怪不得复制构造一直出错，原来把指针删了两次
	CanCopy(const CanCopy&);
	CanCopy& operator=(const CanCopy&);
	~CanCopy();
private:
	// 用于执行清理的函数，可能会在重载赋值和复制构造中使用
	void dispose();
};

/*
 * 定义交换的类
 */
class CanSwap
{
	int value;
	int* pointer;
public:
	CanSwap();
	CanSwap(int v, int v2);
	CanSwap(const CanSwap&);
	friend void swap(CanSwap& p1, CanSwap& p2);
	CanSwap& operator=(CanSwap cs);
	~CanSwap();
};

/*
 * 可以移动的类
 */
class CanMove
{
	char* data;
public:
	CanMove();
	CanMove(char str[]);
	CanMove(const CanMove&);
	// 移动构造函数，参数为右值引用
	// noexcept很重要，只有显示声明不会发生异常，标准库才会优先考虑使用移动构造函数执行移动操作（需要在定义和声明同时添加noexcept）
	CanMove(CanMove&&) noexcept;
	CanMove& operator=(CanMove&&) noexcept;
	~CanMove();
};

class DefaultCopy
{
public:
	// defualt关键字让编译器生成合成构造函数
	DefaultCopy() = default;
	// 声明在类外的默认不是内联函数
	DefaultCopy(const DefaultCopy&);
};

class NoCopy
{
public:
	// 禁止构造和复制构造
	NoCopy() = delete;
	NoCopy(const NoCopy&) = delete;

	// 删除操作还可以定义在其他函数上
	void some_other_thing() = delete;
};

/*
 * 使用引用计数的类
 */
class RefCount
{
	// 引用计数
	int* count;
	// 成员指针
	char* data;
public:
	RefCount();
	RefCount(char str[]);
	RefCount(const RefCount&);
	RefCount& operator=(const RefCount&);
	~RefCount();
private:
	void dispose();
};

void copy_controll();
