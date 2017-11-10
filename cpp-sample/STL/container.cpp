#include "stdafx.h"
#include <unordered_set>
using namespace std;

template <typename T>
string vector2string(const vector<T>& vec)
{
	ostringstream out;
	out << '[';
	for (const T& element : vec)
	{
		out << element << ", ";
	}
	out << ']';
	return out.str();
}

template <typename T>
void print_vector(const vector<T>& vec)
{
	cout << vector2string(vec) << endl;
}

/*
 * ��õ���������
 */
void vectors()
{
	//  C++ 11: list initialize
	vector<int> v1{1,2,3,4};
	cout << vector2string(v1) << endl;

	// add element
	v1.push_back(5);
	print_vector(v1);

	// insert element
	v1.insert(v1.begin(), 0);
	print_vector(v1);


	// iterate vector using foreach
	for (const auto& value : v1)
	{
		cout << value << " ";
	}

	// iterate vector 
	// ������Ҫд���ݵ�ʱ��ʹ��const������
	for (vector<int>::const_iterator it = v1.begin(); it != v1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// reverse iterate vector
	cout << endl;

	for (auto it = v1.rbegin(); it != v1.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// delete element
	v1.pop_back();
	v1.erase(v1.end() - 1);
	v1.erase(v1.begin(), v1.end());
	cout << v1.size() << endl;
}

/*
 * ��׼���������������������������
 */
void arrays()
{
	// ��׼�����飬��Ҫͬʱָ��Ԫ�����ͺ������С
	array<int, 10> a1{1,2,3,4,5};
	for (auto it : a1)
	{
		cout << it << " ";
	}
	cout << endl;
}

/*
 * ����
 */
void lists()
{
	list<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);

	for (auto& e : c)
	{
		cout << e << ", ";
	}
	cout << endl;

	c.assign({1,2,3,4,5,2,3,4,4,5,2,2});
	c.sort();
	c.unique();
	for_each(c.begin(), c.end(), [](int e)
	{
		cout << e << ", ";
	});
	cout << endl;
}

/*
 * ˫������֧����������˳����ʣ�����������ܲ�̫��
 */
void deques()
{
	deque<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_front(0);

	// ����˫������
	for (deque<int>::const_iterator it = c.begin(); it != c.end(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;

	c.insert(c.begin(), 0);

	// ɾ��Ԫ��
	c.pop_front();
	c.pop_back();

	// �������
	for (auto it = c.crbegin(); it != c.crend(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;
}

/*
 * �����������ڲ�֧�ַ���ǰһ���ڵ㣬���Բ����Ƚ�����
 */
void forward_lists()
{
	forward_list<int> list{1,2,3,4,5};
	list.push_front(6);

	// ����ֻ�ܻ�ȡ��һ���ڵ㣬������Ҫһ����ǰ�ڵ�
	for (forward_list<int>::const_iterator it = list.begin(); it != list.cend(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;

	// ���뵽��ǰ��
	list.insert_after(list.before_begin(), 5);
	// ���뵽�ڶ���λ��
	list.insert_after(list.begin(), 6);

	for (auto& e : list)
	{
		cout << e << ", ";
	}
	cout << endl;

	// ɾ��Ԫ��
	list.erase_after(list.before_begin());
	for (auto& e : list)
	{
		cout << e << ", ";
	}
	cout << endl;
}

void associative_containers()
{
	// pair����������ֵ��
	pair<int, int> p{1,2};
	int key = p.first;
	int value = p.second;

	// make_pair����������������pair
	pair<string, int> word_count = make_pair(string("Hello"), 0);

	// ���򼯺�
	unordered_set<int> us1;
	// ���򼯺�
	set<int> s1;
	// �������ظ�������
	unordered_multiset<int> ums1;
	// �������ظ�������
	multiset<int> ms1;

	// �������Ƶ�4��map�������ʡ����

	// ��ʼ������
	set<int> s{1,2,3,4};
	// ����Ԫ��
	s.insert(5);
	s.insert(6);

	// ��������
	for (const auto& e : s)
	{
		cout << e << ", ";
	}
	cout << endl;

	// ��ʼ��map
	map<int, int> m{{1,1},{2,2},{3,3}};
	// ����map
	m.insert({4,4});
	m.insert(make_pair(5, 5));
	for (const auto& e : m)
	{
		cout << "(" << e.first << ", " << e.second << ")";
	}
	cout << endl;
	// �������±����ֵ����ֵ������������ڣ����ʼ����ֵ��
	m[6] = 6;

	// multimap����Ԫ��
	// lower_bound��upper_bound���ظ������Ķ����ֵ�ԣ�Ȼ������ô˷�Χ���е���
	multimap<int, int> mm({{1,1},{1,2},{3,3}});
	for (multimap<int, int>::iterator it = mm.lower_bound(1), end = mm.upper_bound(1);
	     it != end; ++it)
	{
		cout << it->second << ", ";
	}
	cout << endl;
	// ������ʹ��equal_range������
	using multimap_iterator = multimap<int, int>::iterator;
	for (pair<multimap_iterator, multimap_iterator> p = mm.equal_range(1); p.first != p.second; ++p.first)
	{
		cout << p.first->second << ", ";
	}
	cout << endl;

	// ������������Ҫʹ�ù�ϣ��������׼��Ϊ�������ͺ�string�ȱ�׼�����������˹�ϣ����
	unordered_set<string> us{"yitian","wuwuwu","anning","liuliu"};
	us.insert("wang5");
	// ˳��ȷ��
	for (const auto& e : us)
	{
		cout << e << ", ";
	}
	cout << endl;
}
