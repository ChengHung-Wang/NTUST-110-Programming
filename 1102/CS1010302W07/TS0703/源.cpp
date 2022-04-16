// Name: ¤ý¥¿§»
// Date: April 05, 2022
// Last Update: March 13, 2022
// Problem statement: Seven-segment Display

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> digitPoints = {
		"135678", // 0
		"58", // 1
		"15467", // 2
		"15487", // 3
		"3458", // 4
		"13487", // 5
		"136784", // 6
		"158", // 7
		"1345678", // 8
		"134578"// 9
};
char digitStyle[3][3] = {
	//0    1	2
	{' ', '_', ' '},
	//3	   4    5
	{'|', '_', '|'},
	//6    7    8
	{'|', '_', '|'}
};
// _ 
//|_|
//|_|

int main() {
	string input;
	while (cin >> input) {
		map<int, vector<string>> result;
		result[0] = {};
		result[1] = {};
		result[2] = {};
		for (char& item : input) {
			char digitTemp[3][3] = {
				{' ', ' ', ' '},
				{' ', ' ', ' '},
				{' ', ' ', ' '}
			};
			int thisDigit = item - '0';
			for (char& point : digitPoints[thisDigit]) {
					digitTemp[(int)(point - '0') / 3][(int)point % 3] = 
						digitStyle[(int)(point - '0') / 3][(int)point % 3];
			}
			for (int row = 0; row < 3; row++) {
				string strTemp = "";
				for (int col = 0; col < 3; col++) {
					strTemp += digitTemp[row][col];
				}
				result[row].push_back(strTemp);
			}
		}
		for (int row = 0; row < 3; row++) {
			for (string& item : result[row]) {
				cout << item;
			}
			cout << endl;
		}
	}
}