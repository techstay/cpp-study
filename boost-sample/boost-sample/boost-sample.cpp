// boost-sample.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;
using namespace boost::math::constants;
using namespace boost::multiprecision;

int main()
{
	cout << "圆周率π是:" << setprecision(50) << pi<cpp_dec_float_50>() << endl;
	cout << "自然对数e是:" << setprecision(50) << e<cpp_dec_float_50>() << endl;
	cout << "根号2是:" << setprecision(50) << root_two<cpp_dec_float_50>() << endl;
	return 0;
}
