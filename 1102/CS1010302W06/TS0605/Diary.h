// Name: ¤ý¥¿§»
// Date: March 29, 2022
// Last Update: March 13, 2022
// Problem statement: Observation Diary
#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct event {
	string name;
	string content;
};

typedef struct day_log {
	string name;
	vector<event> event_list;
};

class Diary {
public:
	static void NewDay(string input);
	static void NewEvent(string creature_name, string input);
	static vector<day_log> day;
};