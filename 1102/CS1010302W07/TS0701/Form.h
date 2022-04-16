#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <fstream>

using namespace std;

class Word {
public:
	string src, lowerStr;
	map<char, int> usage;
	Word(string);
};

class Form {
public:
	string fileName, inputWord;
	vector<Word> words;
	map<char, int> target;
	void SetInputWord(string);
	void ProcessInputWord();
	void SetFileName(string);
	void Load_CompareWord();
	void PrintFoundWords();
};
