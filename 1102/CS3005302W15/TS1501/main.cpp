// Name: ¤ý¥¿§»
// Date: May 31, 2022
// Last Update: May 31, 2022
// Problem statement: Set Exercise
#include <iostream> // cin, cout support
#include <string> // c++ string feature
#include <set> // set feature
#include <fstream> // file operator

using namespace std;

int main()
{
	ifstream fin("name.txt");
	set<string> names;
	// get elements by getline()
	for (string input; getline(fin, input);)
	{
		names.insert(input);
	}
	fin.close();
	// foreach each item
	for (const auto& item : names)
	{
		cout << item << '\n';
	}
	return 0;
}