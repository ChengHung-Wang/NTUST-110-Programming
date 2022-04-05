// Name: ¤ý¥¿§»
// Date: April 05, 2022
// Last Update: March 13, 2022
// Problem statement: Array to integer
#include <string>
using namespace std;

class Atoi {

private:
	string beTrans;
	
public:
	Atoi() {
		beTrans = "";
	}
	Atoi(string s) {
		beTrans = s;
	}
	void SetString(string s) {
		beTrans = s;
	}
	const string GetString() {
		return beTrans;
	}
	int Length() {
		if (beTrans == "") {
			return 0;
		}
		if (beTrans[0] == '-') {
			return beTrans.length() - 1;
		}
		return beTrans.length();
	}
	bool IsDigital() {
		int index = 0;
		if (beTrans == "") {
			return false;
		}
		for (char& item : beTrans) {
			if (item < '0' || item > '9') {
				if (!(index == 0 && item == '-')) {
					return false;
				}
			}
			index++;
		}
		return true;
	}
	int StringToInteger() {
		if (beTrans == "") {
			return 0;
		}
		return stoi(beTrans);
	}
};