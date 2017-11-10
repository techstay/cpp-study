#include "stdafx.h"
#include <numeric>
#include <functional>
using namespace std;

template <typename T>
void print(const T& c)
{
	for (const auto& e : c)
	{
		cout << e << ", ";
	}
	cout << endl;
}

template <typename TBegin, typename TEnd>
void print(const TBegin& begin, const TEnd& end)
{
	for (auto it = begin; it != end; ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;
}

/*
 * ֻ���㷨
 */
void read_only_algorithms()
{
	vector<int> v1{1,2,3,4};
	vector<int> v2{1,2,4,5};

	// �ۼ�
	int sum_of_v1 = accumulate(v1.begin(), v1.end(), 0);
	cout << "accumulate:" << sum_of_v1 << endl;

	// �Ƚ�
	bool is_equal = equal(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend());
	cout << "equal:" << is_equal << endl;
}

/*
 * д�������㷨
 */

void write_algorithms()
{
	// ���
	vector<int> v(10);
	fill(v.begin(), v.end(), 10);
	print(v);

	// ���n��Ԫ��
	fill_n(v.begin() + 5, 5, 5);
	print(v);

	// ������������൱�ڵ���������push_back()����
	v.clear();
	back_insert_iterator<vector<int>> it = back_inserter(v);
	*it = 1; //v.push_back(1);
	*it = 2; //v.push_back(2);

	// �����������Ҫ���ں����������㷨���ʹ��
	fill_n(back_inserter(v), 5, 5);
	print(v);

	// �����㷨
	vector<int> v1{1,2,3,4};
	decltype(v1) v2(v1.size());
	copy(v1.cbegin(), v1.cend(), v2.begin());
	print(v2);

	// �޸��㷨�����޸�ԭ����
	replace(v1.begin(), v1.end(), 1, 4);
	// �����ϣ���޸�ԭ����������ʹ�ø��ư汾
	v2.clear();
	replace_copy(v1.begin(), v1.end(), back_inserter(v2), 4, 5);
	print(v2);


	// ����
	v.clear();
	v.insert(v.begin(), {1,2,3,4,4,3,2,1});
	sort(v.begin(), v.end());
	print(v);


	v.clear();
	v.insert(v.begin(), {1,1,2,2,3,4,2,3,5,4});
	// ȥ�����ڵ��ظ�Ԫ��
	vector<int>::iterator unique_end = unique(v.begin(), v.end());
	print(v.begin(), v.end());
}

/*
 * ʾ����ͺ���
 */
struct Person
{
	string name;
	int age;

	friend ostream& operator<<(ostream& out, const Person& p)
	{
		out << "Person(" << p.name << "," << p.age << ")";
		return out;
	}
};

bool contain(const string& str, char c)
{
	return str.find_first_of(c) != string::npos;
}

/*
 * lambda���ʽ
 */
void lambdas()
{
	// �򵥵�lambda���ʽ
	auto hello_lambda = [] { cout << "Hello Lambda(��)" << endl; };
	hello_lambda();

	// lambda���ʽ����������Ҫʹ��β�÷�ʽָ��
	int outer = 5;
	auto add = [](int a, int b)-> int { return a + b; };
	cout << "add(3, 5)=" << add(3, 5) << endl;

	// ���ú�ֵ��ʽ�����ⲿ����
	auto get_outer_val = [outer] { return outer; };
	auto get_outer_ref = [&outer] { return outer; };
	outer = 6;
	cout << "outer:" << outer << "  lambda:get_outer_val:" << get_outer_val() << endl;
	cout << "outer:" << outer << "  lambda:get_outer_ref:" << get_outer_ref() << endl;

	// �Զ������ú�ֵ��ʽ����
	auto get_outer_ref_auto = [&] { return outer; };
	auto get_outer_val_auto = [=] { return outer; };
}

/*
* �߽׺��������������ݸ������㷨
*/

void advanced_functions()
{
	// ����ʹ��lambda���ʽָ������ʽ
	vector<Person> v{Person{"yitian",24},Person{"zhang3",25},Person{"li4",30}};
	sort(v.begin(), v.end(), [](Person p1,Person p2)
	{
		return p1.name < p2.name;
	});
	print(v);

	sort(v.begin(), v.end(), [](Person p1,Person p2)
	{
		return p1.age < p2.age;
	});
	print(v);

	vector<int> c{1,2,3,4,5};
	vector<int>::iterator iterator = find_if(c.begin(), c.end(), [](const int& c)
	{
		return c % 2 == 0;
	});
	cout << "��һ��ż����:" << *iterator << endl;

	//��foreach�㷨����
	for_each(c.begin(), c.end(), [](auto e)
	{
		cout << e << ", ";
	});
	cout << endl;

	// ����ռλ�������ռ�
	using namespace std::placeholders;
	string str("Hello world");
	// ��ͨ��ʽ���ú���
	bool res = contain(str, 'w');
	// �������Ͳ����󶨣��Ա���������ͺ������㷨���
	auto contain_w = bind(contain, _1, 'w');
	res = contain_w(str);
}
