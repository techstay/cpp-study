#include "stdafx.h"
#include "oop.h"
using namespace std;

void oop()
{
	cout << "多态性" << endl;
	vector<shared_ptr<Shape>> shapes;
	shapes.push_back(static_pointer_cast<Shape>(make_shared<Square>(1)));
	shapes.push_back(static_pointer_cast<Shape>(make_shared<Rectangle>(3, 4)));
	shapes.push_back(static_pointer_cast<Shape>(make_shared<Triangle>(3, 4, 5)));
	shapes.push_back(static_pointer_cast<Shape>(make_shared<Circle>(1)));
	for (const auto& e : shapes)
	{
		cout << e->getInfo() << endl;
	}
}

void BaseClass::do_it()
{
	cout << "do it" << endl;
}

void DeriveClass::do_something()
{
	cout << "do something" << endl;
}

double Rectangle::getArea()
{
	return a * b;
}

string Rectangle::getInfo()
{
	ostringstream output;
	output << "长方形面积:" << getArea();
	return output.str();
}

double Triangle::getArea()
{
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

string Triangle::getInfo()
{
	ostringstream output;
	output << "三角形面积:" << getArea();
	return output.str();
}

double Circle::getArea()
{
	// C++ 居然没有官方的PI常量
	const double PI = atan(1) * 4;
	return r * r * PI;
}

string Circle::getInfo()
{
	ostringstream output;
	output << "圆形面积:" << getArea();
	return output.str();
}

std::string Square::getInfo()
{
	ostringstream output;
	output << "正方形面积:" << getArea();
	return output.str();
}
