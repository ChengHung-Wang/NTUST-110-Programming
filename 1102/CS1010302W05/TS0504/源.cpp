// Name: ¤ý¥¿§»
// Date: March 17, 2022
// Last Update: March 13, 2022
// Problem statement: Sudoku Checker
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int width = 9, height = 9;

//string filePath = "input.txt";
//string outputFilePath = "output.txt";
vector<vector<map<int, string>>> cube; // cube[number][y][x] = <string>
map<int, map<int, vector<map<int, string>>>> cube3x3; // cube3x3[row / 3][col / 3][row % 3][col % 3] = <string>

vector<string> split(string, char);
string join(vector<string>, string);
bool valid(vector<map<int, string>>, int, bool);
void process(string);

vector<string> split(string src, char splitBy) {
	vector<string> result;
	string buffer = "";
	for (auto& item : src) {
		if (item != splitBy) {
			buffer += item;
		}
		else {
			result.push_back(buffer);
			buffer = "";
		}
	}
	if (buffer != "") {
		result.push_back(buffer);
	}
	return result;
}
string join(vector<string> src, string symbol) {
	string result = "";
	bool first = false;
	for (auto& item : src) {
		if (first) {
			result += symbol;
		}
		else {
			first = true;
		}
		result += item;
	}
	return result;
}

bool valid(vector<map<int, string>> config, int size, bool cross) {
	map<string, int> logs;
	map<string, int> logs2;
	// init
	for (int index = 0; index < size; index++) {
		logs[to_string(index + 1)] = 0;
		logs2[to_string(index + 1)] = 0;
	}
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if (stoi(config[row][col]) <= 0 || stoi(config[row][col]) > 9) {
				return false;
			}
			logs[config[row][col]] ++;
			if (logs[config[row][col]] > 1) {
				return false;
			}
			if (cross) {
				logs2[config[col][row]] ++;
				if (logs2[config[col][row]] > 1) {
					return false;
				}
			}
		}
		if (cross) {
			//  reset;
			for (int index = 0; index < size; index++) {
				logs[to_string(index + 1)] = 0;
				logs2[to_string(index + 1)] = 0;
			}
		}
	}
	return true;
}

void process(string allStr) {
	int row = 0;
	int col = 0;
	vector<map<int, string>> cache;
	map<int, string> colCache;
	for (string& item : split(allStr, ',')) {
		if (row >= 9) { // row == 9
			// row & col reset
			row = 0;
			col = 1;
			cube.push_back(cache);
			cache.clear();
		}
		if (col >= 9) {
			// col reset
			cache.push_back(colCache);
			row++;
			col = 0;
		}
		colCache[col] = item;
		col++;
	}
	cache.push_back(colCache);
	cube.push_back(cache);

	// split to 3x3 cube
	// init
	for (int row = 0; row < height / 3; row++) {
		for (int col = 0; col < width / 3; col++) {
			for (int rowInner = 0; rowInner < 3; rowInner++) {
				//vector<map<int, string>>
				cube3x3[row][col].push_back({
					{0, ""}, {1, ""}, {2, ""}
				});
			}
		}
	}
	// valid
	for (vector<map<int, string>>& item : cube) {
		bool pass = true;
		if (valid(item, 9, true)) {
			for (int row = 0; row < height; row++) {
				for (int col = 0; col < width; col++) {
					cube3x3[row / 3][col / 3][row % 3][col % 3] = item[row][col];
				}
			}
			// valid for 3x3 cube
			for (int row = 0; row < height / 3; row++) {
				for (int col = 0; col < width / 3; col++) {
					if (!valid(cube3x3[row][col], 3, false)) {
						pass = false;
					}
				}
			}
		}
		else {
			pass = false;
		}
		cout << (pass ? "True" : "False") << endl;
	}
}
int main() {
	//ifstream file(filePath);
	//ofstream outputFile(outputFilePath);
	string buffer;
	string allStr = "";
	
	int count = 1;

	while (getline(cin, buffer)) {
		if (buffer == "") {
			continue;
		}
		allStr += buffer + ",";
		if (count >= width) {
			process(allStr);
			allStr = "";
			count = 0;
			cube.clear();
		}
		count++;
	}

	
	//outputFile.close();
	return 0;
}