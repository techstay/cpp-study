#include "stdafx.h"
#include "operator_overloading.h"

using namespace std;

/*
 * 加法运算符可以使用复合运算符来简化操作
 */
MyClass operator+(const MyClass& a, const MyClass& b)
{
	MyClass obj = a;
	obj += b;
	return obj;
}

MyClass& MyClass::operator+=(const MyClass& b)
{
	this->val += b.val;
	return *this;
}

MyClass& MyClass::operator++()
{
	val++;
	return *this;
}

MyClass& MyClass::operator--()
{
	val--;
	return *this;
}

MyClass MyClass::operator--(int)
{
	MyClass obj = *this;
	// 后置递增递减应该调用前置递增递减
	--*this;
	return obj;
}

MyClass MyClass::operator++(int)
{
	auto obj = *this;
	++*this;
	return obj;
}

void MyClass::operator()()
{
	cout << "No param call" << endl;
}

void MyClass::operator()(int n)
{
	cout << "One param call:" << n << endl;
}

MyClass::operator int() const
{
	return val;
}

MyClass::operator bool() const
{
	return val != 0;
}

ostream& operator<<(ostream& out, const MyClass& obj)
{
	out << "MyClass(" << obj.val << ")" << flush;
	return out;
}

istream& operator>>(istream& in, MyClass& obj)
{
	in >> obj.val;
	if (!in)
	{
		obj.val = 0;
	}
	return in;
}

bool operator==(const MyClass& a, const MyClass& b)
{
	return a.val == b.val;
}

bool operator!=(const MyClass& a, const MyClass& b)
{
	return !(a == b);
}

bool operator<(const MyClass& a, const MyClass& b)
{
	return a.val < b.val;
}

bool operator>(const MyClass& a, const MyClass& b)
{
	return a.val > b.val;
}

bool operator<=(const MyClass& a, const MyClass& b)
{
	return !(a > b);
}

bool operator>=(const MyClass& a, const MyClass& b)
{
	return !(a < b);
}

void operator_overloading()
{
	MyClass v1, v2;

	cout << "v1:" << v1 << endl;
	cout << "v2:" << v2 << endl;
	cout << "v1==v2:" << (v1 == v2) << endl;
	cout << "v1<v2:" << (v2 < v2) << endl;
	cout << "v1++:" << v1++ << endl;
	cout << "++v2:" << ++v2 << endl;

	MyList l1;
	l1 = {1,2,3,4,5};
}

MyList& MyList::operator=(initializer_list<int> list)
{
	for (const auto& i : this->list)
	{
		this->list.push_back(i);
	}
	return *this;
}

int& MyList::operator[](std::size_t n)
{
	return list[n];
}

const int& MyList::operator[](std::size_t n) const
{
	return list[n];
}
