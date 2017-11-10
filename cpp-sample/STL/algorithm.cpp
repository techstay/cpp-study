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
 * 只读算法
 */
void read_only_algorithms()
{
	vector<int> v1{1,2,3,4};
	vector<int> v2{1,2,4,5};

	// 累加
	int sum_of_v1 = accumulate(v1.begin(), v1.end(), 0);
	cout << "accumulate:" << sum_of_v1 << endl;

	// 比较
	bool is_equal = equal(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend());
	cout << "equal:" << is_equal << endl;
}

/*
 * 写容器的算法
 */

void write_algorithms()
{
	// 填充
	vector<int> v(10);
	fill(v.begin(), v.end(), 10);
	print(v);

	// 填充n个元素
	fill_n(v.begin() + 5, 5, 5);
	print(v);

	// 插入迭代器，相当于调用容器的push_back()方法
	v.clear();
	back_insert_iterator<vector<int>> it = back_inserter(v);
	*it = 1; //v.push_back(1);
	*it = 2; //v.push_back(2);

	// 插入迭代器主要用于和其他泛型算法配合使用
	fill_n(back_inserter(v), 5, 5);
	print(v);

	// 复制算法
	vector<int> v1{1,2,3,4};
	decltype(v1) v2(v1.size());
	copy(v1.cbegin(), v1.cend(), v2.begin());
	print(v2);

	// 修改算法，会修改原容器
	replace(v1.begin(), v1.end(), 1, 4);
	// 如果不希望修改原容器，可以使用复制版本
	v2.clear();
	replace_copy(v1.begin(), v1.end(), back_inserter(v2), 4, 5);
	print(v2);


	// 排序
	v.clear();
	v.insert(v.begin(), {1,2,3,4,4,3,2,1});
	sort(v.begin(), v.end());
	print(v);


	v.clear();
	v.insert(v.begin(), {1,1,2,2,3,4,2,3,5,4});
	// 去除相邻的重复元素
	vector<int>::iterator unique_end = unique(v.begin(), v.end());
	print(v.begin(), v.end());
}

/*
 * 示例类和函数
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
 * lambda表达式
 */
void lambdas()
{
	// 简单的lambda表达式
	auto hello_lambda = [] { cout << "Hello Lambda(λ)" << endl; };
	hello_lambda();

	// lambda表达式返回类型需要使用尾置方式指定
	int outer = 5;
	auto add = [](int a, int b)-> int { return a + b; };
	cout << "add(3, 5)=" << add(3, 5) << endl;

	// 引用和值方式捕获外部变量
	auto get_outer_val = [outer] { return outer; };
	auto get_outer_ref = [&outer] { return outer; };
	outer = 6;
	cout << "outer:" << outer << "  lambda:get_outer_val:" << get_outer_val() << endl;
	cout << "outer:" << outer << "  lambda:get_outer_ref:" << get_outer_ref() << endl;

	// 自动以引用和值方式捕获
	auto get_outer_ref_auto = [&] { return outer; };
	auto get_outer_val_auto = [=] { return outer; };
}

/*
* 高阶函数，将函数传递给泛型算法
*/

void advanced_functions()
{
	// 排序，使用lambda表达式指定排序方式
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
	cout << "第一个偶数是:" << *iterator << endl;

	//用foreach算法迭代
	for_each(c.begin(), c.end(), [](auto e)
	{
		cout << e << ", ";
	});
	cout << endl;

	// 引入占位符命名空间
	using namespace std::placeholders;
	string str("Hello world");
	// 普通方式调用函数
	bool res = contain(str, 'w');
	// 将函数和参数绑定，以便和其他泛型函数及算法配合
	auto contain_w = bind(contain, _1, 'w');
	res = contain_w(str);
}
