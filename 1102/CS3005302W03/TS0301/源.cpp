// Name: ¤ý¥¿§»
// Date: March 7, 2022
// Last Update: March 7, 2022
// Problem statement: Occurrenc Counting
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi; // parseInt()
using std::to_string; // toString()
using std::sort; // sort() method

// methods
vector<string> split(string src, char splitBy);

// method practical
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
	string input;
	map<string, int> config;
	vector<map<string, string>> configList;
	getline(cin, input);
	for (auto& item : split(input, ' ')) {
		if (config.find(item) == config.end()) {
			config[item] = 1;
		}
		else {
			config[item] += 1;
		}
	}
	// map to vector
	for (auto& item : config) {
		map<string, string> cache;
		cache["key"] = item.first;
		cache["value"] = to_string(item.second);
		configList.push_back(cache);
	}
	sort(
		configList.begin(),
		configList.end(),
		[](map<string, string> itemA, map<string, string> itemB) {
			// sort by key DESC
			return stoi(itemA["key"]) > stoi(itemB["key"]); 
		}
	);
	cout << "N\tcount" << endl;
	for (map<string, string>& item : configList) {
		cout << item["key"] << "\t" << item["value"] << endl;
	}
	return 0;
}