// Name: ¤ý¥¿§»
// Date: February 24, 2022
// Last Update: February 24, 2022
// Problem statement: Adding Large Numbers
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

string errMessage = "Not a valid number, please try again.";

string calc(string first, string second) {
	string result = "";
	int carry;
	vector<int> cache;
	int length = std::max(first.size(), second.size());
	first = std::string(length - first.length(), '0') + first;
	second = std::string(length - second.length(), '0') + second;
	// init
	cache.push_back(0);
	cache.push_back(0);
	for (int index = length - 1; index >= 0; index--) {
		int nowA = first.at(index) - 48;
		int nowB = second.at(index) - 48;
		int carry = cache[0];
		string calcResult = std::to_string(nowA + nowB + carry);

		// format
		calcResult = std::string(2 - calcResult.length(), '0') + calcResult;
	
		// reset
		cache.clear();

		cache.push_back(std::int32_t(calcResult.at(0)) - 48);
		cache.push_back(std::int32_t(calcResult.at(1)) - 48);
		
		result.push_back(calcResult.at(1));
	}
	if (cache[0] != 0) {
		result.push_back(cache[0] + 48); // int to char => int + 48
	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	int limit;
	while (std::cin >> limit) {
		for (int index = 0; index < limit; index++) {
			vector<string> config;
			bool auth = true;
			string cache = "";
			// get number A
			std::cin >> cache;
			config.push_back(cache);
			cache = ""; // reset; 
			std::cin >> cache;
			config.push_back(cache);
			
			for (char& c : config[0]) {
				if (!(c >= '0' && c <= '9')) {
					auth = false;
				}
			}
			for (char& c : config[1]) {
				if (!(c >= '0' && c <= '9')) {
					auth = false;
				}
			}

			std::cout << (auth ? calc(config[0], config[1]) : errMessage) << std::endl;
		}
		break;
	}
	
	return 0;
}