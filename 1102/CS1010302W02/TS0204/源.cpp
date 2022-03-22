// Name: ¤ý¥¿§»
// Date: February 24, 2022
// Last Update: February 24, 2022
// Problem statement: Print Standard Format
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<map<string, string>> config;
map<string, int> length;

void resetLengthRecord() {
	length["name"] = 0;
	length["salary"] = 0;
	length["bonus"] = 0;
}

int main() 
{
	int limit;
	while (std::cin >> limit) {
		// reset
		resetLengthRecord();
		config.clear();

		for (int index = 0; index < limit; index++) {
			map<string, string> cache;
			std::cin >> cache["name"];
			std::cin >> cache["salary"];
			std::cin >> cache["bonus"];

			#pragma region update longest length from every column
			if (cache["name"].size() > length["name"]) 
			{
				length["name"] = cache["name"].size();
			}
			if (cache["salary"].size() > length["salary"])
			{
				length["salary"] = cache["salary"].size();
			}
			if (cache["bonus"].size() > length["bonus"])
			{
				length["bonus"] = cache["bonus"].size();
			}
			#pragma endregion

			config.push_back(cache);
		}
		for (int index = 0; index < limit; index++) {
			std::cout
				<<
				std::string(length["name"] - config[index]["name"].size(), ' ')
				<< config[index]["name"]
				<< "|  " <<
				std::string(length["salary"] - config[index]["salary"].size(), ' ')
				<< config[index]["salary"]
				<< "|  " <<
				std::string(length["bonus"] - config[index]["bonus"].size(), ' ')
				<< config[index]["bonus"]
				<< "\n";
		}
	}
	
	return 0;
}