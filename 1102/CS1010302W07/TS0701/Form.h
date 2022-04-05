#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Form
{
private:

public:
	string word, name;
	vector<string> output;
	void SetInputWord(string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};
