#include "stdafx.h"
using namespace std;

void smart_pointers()
{
	// ����һ���յĹ�������ָ��
	shared_ptr<string> sp;
	// ��ָ�븳ֵ
	sp = make_shared<string>("hello");
	if (sp && sp->empty())
	{
	}
	else
	{
		cout << *sp << endl;
	}
	// ��ȡ����ָ���б������ָ�룬һ�㲻Ӧ����
	string* str_p = sp.get();
	// ��������ָ�룬���ü�����һ
	auto sp2 = sp;
	// �жϵ�ǰ����ָ���Ƿ�ֻ��һ������
	bool is_unique = sp.unique();
	cout << "is_unique:" << is_unique << endl;;
	// ��ȡ���еĹ�������ָ����������Ҫ���ڵ���
	int count = sp.use_count();
	cout << "count:" << count << endl;
	// ��ʱ���ڴ�ķ�����ͷŲ���ʹ��new��delete������Ҫ����ɾ����
	// ���ͷ��ڴ��ʱ������ɾ�������ͷ�
	auto assign = [] { return new int(5); };
	auto release = [](int* p) { delete p; };
	shared_ptr<int> sp3(assign(), release);

	// unique_ptrָ��Ķ����ǵ����ģ����ܹ���
	unique_ptr<int> up = make_unique<int>(5);
	// ����ָ�벢������ָ���ÿ�
	int* pointer = up.release();
	auto up3 = unique_ptr<int>(pointer);
	// �ͷ���Ӧ����
	up3.reset();
	// ������ָ����µ�ָ���
	up3.reset(new int(5));


	// ������ָ�룬�����������ü�����ʹ��������ָ���ʱ���п���ʵ�ʶ����ѱ��ͷ�
	weak_ptr<int> wp = make_shared<int>(5);
	// �������ü���
	int use_count = wp.use_count();
	// �ж�ʵ�ʶ����Ƿ����
	bool is_expired = wp.expired();
	// ��ʵ�ʶ�����ڣ����ظö��󣬷��򷵻ؿ�����ָ��
	shared_ptr<int> actual_ptr = wp.lock();
}

void manual_memory_controll()
{
	// ��̬����һ���ڴ�
	int* p1 = new int(5);
	cout << *p1 << endl;
	// ����ڴ�
	delete p1;
	// �������պ�ָ�����㣬��ֹ����δ��������
	p1 = nullptr;

	// �����ڴ治�����䣬���ܳ�bad_alloc�쳣���������new���������ݲ���������
	// ��ʱ����������ڴ�ʧ�ܣ��᷵�ؿ�ָ��
	int* p2 = new(nothrow) int(100);
}

/*
 * �������ڴ�ͳ�ʼ������ķ�����
 */
void allocators()
{
	const int N = 10;
	// ����һ�����Է���string��allocator
	allocator<string> alloc;
	// ����ɱ���ָ���������ݵ������ڴ棬��Щ�ڴ���ԭʼ�ڴ棬��δ���г�ʼ�������ʲôҲ������
	allocator<string>::pointer pointer = alloc.allocate(N);
	// Ϊ��������ԭʼ�ڴ��ʼ������
	for (int i = 0; i < N; ++i)
	{
		alloc.construct(pointer + i, to_string(i));
	}
	// �����ڴ��е�ÿ������
	for (int i = 0; i < N; ++i)
	{
		cout << pointer[i] << ", ";
	}
	cout << endl;
	// �ͷ�ÿ���ڴ�ռ������
	for (int i = 0; i < N; ++i)
	{
		alloc.destroy(pointer + i);
	}
	// �ͷ������ڴ�
	alloc.deallocate(pointer, N);
}
