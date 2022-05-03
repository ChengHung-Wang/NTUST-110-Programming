//// Name: ¤ý¥¿§»
//// Date: February 17, 2022
//// Last Update: February 17, 2022
//// Problem statement: The Translation Machine
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//map<char, vector<char>> getCharConfig(map<char, vector<char>>);
//bool varifyPair(string, string, map<char, vector<char>>);
//int indexOf(char, vector<char>);
//
//map<char, vector<char>> getCharConfig(map<char, vector<char>> tranConfig) {
//	map<char, vector<char>> result;
//	for (int index = 0; index < 26; index++) {
//		result['a' + index] = {};
//	}
//	for (const auto& item : tranConfig) {
//		result[item.first] = item.second;
//	}
//	return result;
//}
//
//bool varifyPair(string src, string target, map<char, vector<char>> dictionary) {
//	if (src.length() != target.length()) {
//		return false;
//	}
//
//	if (src == target) {
//		return true;
//	}
//
//	for (int index = 0; index < target.size(); index++) {
//		if (indexOf(target[index], dictionary[src[index]]) == -1) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int indexOf(char find, vector<char> range) {
//	int index = 0;
//	for (const char& item : range) {
//		if (find == item) {
//			return index;
//		}
//		index++;
//	}
//	return -1;
//}
//
//int main() {
//	int tranLimit, varifyLimit;
//	map<char, vector<char>> tranConfig;
//	cin >> tranLimit >> varifyLimit;
//	for (int index = 0; index < tranLimit; index++) {
//		char src, target;
//		cin >> src >> target;
//		if (tranConfig.find(src) == tranConfig.end()) {
//			tranConfig[src] = { src };
//		}
//		if (tranConfig.find(target) == tranConfig.end()) {
//			tranConfig[target] = { target };
//		}
//		tranConfig[src].push_back(target);
//		tranConfig[target].push_back(src);
//	}
//	for (const auto& item : tranConfig) {
//		char thisChar = item.first;
//		/*for (char& main : item.second) {
//
//		}*/
//	}
//	map<char, vector<char>> dictionary = getCharConfig(tranConfig);
//	for (int index = 0; index < varifyLimit; index++) {
//		string src, target;
//		cin >> src >> target;
//		cout << (varifyPair(src, target, dictionary) ? "yes" : "no") << endl;
//	}
//}