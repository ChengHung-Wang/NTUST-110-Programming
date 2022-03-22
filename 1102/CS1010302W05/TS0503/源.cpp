// Name: ¤ý¥¿§»
// Date: March 17, 2022
// Last Update: March 13, 2022
// Problem statement: Student Records
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int firstNameSize = 25;
int lastNameSize = 30;
int phoneSize = 15;	
vector<string> authMethod = {
	"insert", "delete", "print", "search"
};

vector<string> split(string, char);
inline bool isInteger(const std::string& s);
void del(map<string, string>);
void insert(map<string, string>);
void printConfig();
int search(map<string, string>, bool);
bool configValid(map<string, string>);

vector<map<string, string>> sql;

inline bool isInteger(const std::string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

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

void del(map<string, string> config) {
	string errMess = "Delete Error";
	int delIndex = search(config, false);
	if (! configValid(config)) {
		cout << errMess << endl;
		return;
	}
	if (delIndex < 0) {
		cout << errMess << endl;
		return;
	}
	sql.erase(sql.begin() + delIndex);
}

void insert(map<string, string> config) {
	bool valid = true;
	string errMess = "Insert Error";
	if (! configValid(config)) {
		cout << errMess << endl;
		return;
	}
	if (search(config, false) >= 0) {
		cout << errMess << endl;
		return;
	}
	if (sql.size() >= 10) {
		cout << errMess << endl;
		return;
	}
	sql.push_back(config);
}

int search(map<string, string> config, bool mess) {
	string errMess = "Search Error";
	bool isFind = false;
	int index = 0;
	if (!configValid(config)) {
		if (mess) {
			cout << errMess << endl;
		}
		return -1;
	}
	for (auto& item : sql) {
		if (
			item["firstName"] == config["firstName"] &&
			item["lastName"] == config["lastName"] &&
			item["phone"] == config["phone"]
		) {
			isFind = true;
			return index;
		}
		index++;
	}
	if (mess) {
		cout << errMess << endl;
	}
	return -1;
}

void printConfig() {
	string errMess = "Print Error";
	if (sql.size() <= 0) {
		cout << errMess << endl;
	}
	else {
		for (auto& item : sql) {
			cout << item["firstName"] << " " << item["lastName"] << " " << item["phone"] << endl;
		}
	}
}

bool configValid(map<string, string> config) {
	return !(
		config["firstName"].size() > firstNameSize ||
		config["lastName"].size() > lastNameSize ||
		config["phone"].size() > phoneSize ||
		! isInteger(config["phone"])
	);
}

int main() {
	string str;
	while (getline(cin, str)) {
		if (str.size() < 2) {
			continue;
		}
		vector<string> thisCache = split(str, ' ');
		// check method valid
		if (find(authMethod.begin(), authMethod.end(), thisCache[0]) == authMethod.end()) {
			cout << "Input Error" << endl;
		}
		else if (thisCache[0] != "print" && thisCache.size() != 4) {
			map<string, string> transfer;
			transfer["insert"] = "Insert";
			transfer["delete"] = "Delete";
			transfer["search"] = "Search";
			transfer["print"] = "Print";
			cout << transfer[thisCache[0]] << " Error" << endl;
		}
		else {
			map<string, string> thisConfig;
			if (thisCache[0] != "print") {
				thisConfig["firstName"] = thisCache[1];
				thisConfig["lastName"] = thisCache[2];
				thisConfig["phone"] = thisCache[3];
				if (! configValid(thisConfig)) {
					cout << "Input Error" << endl;
					continue;
				}
				if (thisCache[0] == "insert") {
					insert(thisConfig);
				}
				if (thisCache[0] == "search") {
					int index = search(thisConfig, true);
					if (index >= 0) {
						cout << index << endl;
					}
				}
				if (thisCache[0] == "delete") {
					del(thisConfig);
				}
			}
			else {
				printConfig();
			}
		}
	}
}