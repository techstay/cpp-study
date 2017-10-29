#include "stdafx.h"

using namespace std;

void string_stream()
{
	const string some_lines = "I have a dream."
		"You have a dream too.\n"
		"We all have dreams.";

	istringstream input(some_lines);
	for (string word; input >> word;)
	{
		cout << word << " " << flush;
	}
	cout << endl;

	ostringstream output;
	output << "1 + 1 = " << 2 << endl;
	output << "2 + 2 = " << 4 << endl;
	cout << output.str() << endl;
}
