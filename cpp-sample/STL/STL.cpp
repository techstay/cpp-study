// STL.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "declaration.h"

using namespace std;

int main()
{
	cout << "---------容器----------" << endl;
	cout << "---------vector----------" << endl;
	vectors();
	cout << "---------array----------" << endl;
	arrays();
	cout << "---------deque----------" << endl;
	deques();
	cout << "---------forward_list----------" << endl;
	forward_lists();
	cout << "---------list----------" << endl;
	lists();
	cout << "---------容器适配器----------" << endl;
	cout << "---------stack----------" << endl;
	stacks();
	cout << "---------queue----------" << endl;
	queues();
	cout << "---------泛型算法----------" << endl;
	cout << "---------只读算法----------" << endl;
	read_only_algorithms();
	cout << "---------写容器的算法----------" << endl;
	write_algorithms();
	cout << "---------lambda表达式----------" << endl;
	lambdas();
	cout << "---------高阶函数----------" << endl;
	advanced_functions();
	cout << "---------关联容器----------" << endl;
	associative_containers();
	return 0;
}
