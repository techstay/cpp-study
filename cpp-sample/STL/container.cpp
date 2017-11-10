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
 * 最常用的向量容器
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
	// 当不需要写数据的时候使用const迭代器
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
 * 标准库的数组容器，和内置数组类似
 */
void arrays()
{
	// 标准库数组，需要同时指定元素类型和数组大小
	array<int, 10> a1{1,2,3,4,5};
	for (auto it : a1)
	{
		cout << it << " ";
	}
	cout << endl;
}

/*
 * 链表
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
 * 双向链表，支持随机插入和顺序访问，随机访问性能不太好
 */
void deques()
{
	deque<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_front(0);

	// 遍历双向链表
	for (deque<int>::const_iterator it = c.begin(); it != c.end(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;

	c.insert(c.begin(), 0);

	// 删除元素
	c.pop_front();
	c.pop_back();

	// 反向遍历
	for (auto it = c.crbegin(); it != c.crend(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;
}

/*
 * 单向链表，由于不支持访问前一个节点，所以操作比较特殊
 */
void forward_lists()
{
	forward_list<int> list{1,2,3,4,5};
	list.push_front(6);

	// 由于只能获取下一个节点，所以需要一个超前节点
	for (forward_list<int>::const_iterator it = list.begin(); it != list.cend(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;

	// 插入到最前面
	list.insert_after(list.before_begin(), 5);
	// 插入到第二个位置
	list.insert_after(list.begin(), 6);

	for (auto& e : list)
	{
		cout << e << ", ";
	}
	cout << endl;

	// 删除元素
	list.erase_after(list.before_begin());
	for (auto& e : list)
	{
		cout << e << ", ";
	}
	cout << endl;
}

void associative_containers()
{
	// pair可以用作键值对
	pair<int, int> p{1,2};
	int key = p.first;
	int value = p.second;

	// make_pair函数可以用于生成pair
	pair<string, int> word_count = make_pair(string("Hello"), 0);

	// 无序集合
	unordered_set<int> us1;
	// 有序集合
	set<int> s1;
	// 键可以重复的无序集
	unordered_multiset<int> ums1;
	// 键可以重复的无序集
	multiset<int> ms1;

	// 还有类似的4种map，这里就省略了

	// 初始化集合
	set<int> s{1,2,3,4};
	// 插入元素
	s.insert(5);
	s.insert(6);

	// 遍历集合
	for (const auto& e : s)
	{
		cout << e << ", ";
	}
	cout << endl;

	// 初始化map
	map<int, int> m{{1,1},{2,2},{3,3}};
	// 插入map
	m.insert({4,4});
	m.insert(make_pair(5, 5));
	for (const auto& e : m)
	{
		cout << "(" << e.first << ", " << e.second << ")";
	}
	cout << endl;
	// 可以用下标访问值的左值，假如键不存在，会初始化键值对
	m[6] = 6;

	// multimap访问元素
	// lower_bound和upper_bound返回给定键的多个键值对，然后可以用此范围进行迭代
	multimap<int, int> mm({{1,1},{1,2},{3,3}});
	for (multimap<int, int>::iterator it = mm.lower_bound(1), end = mm.upper_bound(1);
	     it != end; ++it)
	{
		cout << it->second << ", ";
	}
	cout << endl;
	// 还可以使用equal_range来访问
	using multimap_iterator = multimap<int, int>::iterator;
	for (pair<multimap_iterator, multimap_iterator> p = mm.equal_range(1); p.first != p.second; ++p.first)
	{
		cout << p.first->second << ", ";
	}
	cout << endl;

	// 无序容器，需要使用哈希函数，标准库为内置类型和string等标准库类型重载了哈希函数
	unordered_set<string> us{"yitian","wuwuwu","anning","liuliu"};
	us.insert("wang5");
	// 顺序不确定
	for (const auto& e : us)
	{
		cout << e << ", ";
	}
	cout << endl;
}
