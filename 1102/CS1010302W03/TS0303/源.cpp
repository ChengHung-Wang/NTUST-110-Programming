// Name: タЩ
// Date: March 03, 2022
// Last Update: March 03, 2022
// Problem statement: Input_Output3
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
using std::string;
using std::cin;
using std::stoi;
using std::cout;
using std::endl;

enum class inputStatus { num, length, decimal, padStr };

string leftPad(string str, string padStr, int length);
vector<string> split(string str, char splitBy);
string process(map<string, string> config);
inputStatus next(inputStatus now);

string leftPad(string str, string padStr, int length) {
	int authFillLength = length - str.size();
	string result = "";
	for (int index = 0; index < authFillLength; index++) {
		int size = padStr.size();
		if (index >= size) {
			result += padStr.substr(index % size, 1);
		}
		else {
			result += padStr.substr(index, 1);
		}
	}
	return result + str;
}

vector<string> split(string str, char splitBy) {
	vector<string> result;
	vector<char> charArr(str.begin(), str.end());
	string cache = "";
	for (int index = 0; index < str.size(); index++) {
		if (charArr[index] == splitBy && cache != "") {
			result.push_back(cache);
			cache = "";
		}
		else {
			cache += charArr[index];
		}
	}
	if (cache != "") {
		result.push_back(cache);
	}
	return result;
}

string process(map<inputStatus, string> config) {
	string result = "";
	vector<string> number = split(config[inputStatus::num], '.');
	if (stoi(config[inputStatus::decimal]) == 0) {
		config[inputStatus::num] = number[0];
	}
	else {
		if (number.size() >= 2) { // セΤ计翴
			string decimal = number[1].substr(0, stoi(config[inputStatus::decimal]));
			if (decimal.size() < stoi(config[inputStatus::decimal])) { // 干0
				decimal = decimal + string(stoi(config[inputStatus::decimal]) - decimal.size(), '0');
			}
			config[inputStatus::num] = number[0] + "." + decimal; // 计翴
		}
		else if (stoi(config[inputStatus::decimal]) > 0 && number.size() == 1) { // ⊿计计翴玱﹚材碭
			config[inputStatus::num] = number[0] + "." + string(stoi(config[inputStatus::decimal]), '0');
		}
	}
	result = leftPad(
		config[inputStatus::num],
		config[inputStatus::padStr],
		stoi(config[inputStatus::length])
	);
	return result;
}

inputStatus next(inputStatus now) {
	inputStatus result = inputStatus::num;
	switch (now)
	{
	case inputStatus::num:
		result = inputStatus::length;
		break;
	case inputStatus::length:
		result = inputStatus::decimal;
		break;
	case inputStatus::decimal:
		result = inputStatus::padStr;
		break;
	case inputStatus::padStr:
		result = inputStatus::num;
		break;
	}
	return result;
}

int main() {
	map<inputStatus, string> input;

	char cache;
	bool isSplit = false; // if previous is space to split
	inputStatus nowStatus = inputStatus::num;

	while (cin.get(cache)) {
		if (cache == '\n' && nowStatus == inputStatus::padStr) {
			cout << process(input) << endl;
			// reset
			nowStatus = inputStatus::num;
			isSplit = false;
			input.clear();
		}
		else if (cache == ' ') {
			if (isSplit) { // space padSring
				input[inputStatus::padStr] = cache;
			}
			else {
				nowStatus = next(nowStatus);
			}
			isSplit = !isSplit;
		}
		else {
			input[nowStatus] += cache;
			isSplit = false;
		}
	}

	return 0;
}
