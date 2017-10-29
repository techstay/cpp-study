#include "stdafx.h"
using namespace std;

void file_io()
{
	const auto host_file_location = "C:\\Windows\\System32\\drivers\\etc\\hosts";
	ifstream host_file(host_file_location, fstream::in);
	for (char c; host_file.get(c);)
	{
		cout << c << flush;
	}
	host_file.close();

	ofstream out("D:\\hello.txt", fstream::out);
	out << "Hello yitian!" << endl;
	out.close();
}
