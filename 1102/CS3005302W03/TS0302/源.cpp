// Name: ������
// Date: March 7, 2022
// Last Update: March 7, 2022
// Problem statement: Text-based histogram
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// global variable
map<string, int> config;
string filePath = "grade.txt";
string outputFilePath = "grades.Output";

// methods register
void configInit();
vector<string> split(string src, char splitBy);

// method practical
void configInit() {
	config["0"] = 0;
	config["1"] = 0;
	config["2"] = 0;
	config["3"] = 0;
	config["4"] = 0;
	config["5"] = 0;
}

vector<string> split(string src, char splitBy) {
	vector<string> result;
	string cache = "";
	for (int index = 0; index < src.length(); index++) {
		if (src[index] == splitBy && cache != "") {
			result.push_back(cache);
			cache = "";
		}
		else {
			cache += src[index];
		}
	}
	if (cache != "") {
		result.push_back(cache);
	}
	return result;
}

int main() {
	configInit(); // init config

	ifstream file(filePath);
	ofstream outputFile(outputFilePath);
	string line, output = "";

	if (file.is_open()) {
		while (getline(file, line)) {
			for (auto& item : split(line, ' ')) {
			}
			// fill output
			for (int index = 0; index <= 5; index++) {
				output += to_string(config[to_string(index)]) + " grade(s) of " + to_string(index) + "\n";
			}
			configInit(); // reset config
		}
		file.close();
	}
	if (outputFile.is_open()) {
		outputFile << output;
		outputFile.close();
	}

	return 0;
}
