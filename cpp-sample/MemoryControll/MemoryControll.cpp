// MemoryControll.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "declaration.h"

using namespace std;

int main()
{
	cout << "---------智能指针----------" << endl;
	smart_pointers();
	cout << "---------手动分配内存----------" << endl;
	manual_memory_controll();
	cout << "---------分配器----------" << endl;
	allocators();
	return 0;
}
