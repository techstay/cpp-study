#pragma once
#include "stdafx.h"

class CanCopy
{
	std::string name;
	char* data;
public:
	CanCopy();
	CanCopy(std::string, std::string);
	// ���ƹ��캯�����ղ����˶��壬�ֲ��ø��ƹ���һֱ����ԭ����ָ��ɾ������
	CanCopy(const CanCopy&);
	CanCopy& operator=(const CanCopy&);
	~CanCopy();
private:
	// ����ִ������ĺ��������ܻ������ظ�ֵ�͸��ƹ�����ʹ��
	void dispose();
};

/*
 * ���彻������
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
 * �����ƶ�����
 */
class CanMove
{
	char* data;
public:
	CanMove();
	CanMove(char str[]);
	CanMove(const CanMove&);
	// �ƶ����캯��������Ϊ��ֵ����
	// noexcept����Ҫ��ֻ����ʾ�������ᷢ���쳣����׼��Ż����ȿ���ʹ���ƶ����캯��ִ���ƶ���������Ҫ�ڶ��������ͬʱ���noexcept��
	CanMove(CanMove&&) noexcept;
	CanMove& operator=(CanMove&&) noexcept;
	~CanMove();
};

class DefaultCopy
{
public:
	// defualt�ؼ����ñ��������ɺϳɹ��캯��
	DefaultCopy() = default;
	// �����������Ĭ�ϲ�����������
	DefaultCopy(const DefaultCopy&);
};

class NoCopy
{
public:
	// ��ֹ����͸��ƹ���
	NoCopy() = delete;
	NoCopy(const NoCopy&) = delete;

	// ɾ�����������Զ���������������
	void some_other_thing() = delete;
};

/*
 * ʹ�����ü�������
 */
class RefCount
{
	// ���ü���
	int* count;
	// ��Աָ��
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
