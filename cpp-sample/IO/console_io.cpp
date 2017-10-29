#include "stdafx.h"
using namespace std;

void console_io()
{
	cout << "INput your name:" << endl;
	string name;
	cin >> name;
	cout << "Hello, " << name << "\n" << flush;
	cout << unitbuf << "Nice to see you! " << name << "\n" << nounitbuf;
}
