#include "Form.h"

void Form::SetInputWord(string input) {
	inputWord = input;
}

void Form::ProcessInputWord() {
	for (int index = 0; index < 26; index++) {
		target['a' + index] = 0;
	}
	for (char& item : inputWord) {
		target[tolower(item)] ++;
	}
}

void Form::SetFileName(string name) {
	fileName = name;
}

void Form::Load_CompareWord() {
	ifstream file;
	string lineContent;
	file.open(fileName, ifstream::in);
	while (file >> lineContent) {
		words.push_back(Word(lineContent));
	}
	file.close();
}

void Form::PrintFoundWords() {
	for (Word& item : words) {
		bool valid = true;
		for (const auto& usage : item.usage) {
			if (target[usage.first] <= 0 || usage.second > target[usage.first]) {
				valid = false;
				break;
			}
		}
		if (valid) {
			cout << item.src << endl;
		}
	}
}

Word::Word(string _src) {
	src = _src;
	lowerStr = "";
	usage.clear();
	for (char& item : _src) {
		char thisItem = tolower(item);
		lowerStr += thisItem;
		if (usage.find(thisItem) == usage.end()) {
			usage[thisItem] = 1;
		}
		else {
			usage[thisItem] ++;
		}
	}
}