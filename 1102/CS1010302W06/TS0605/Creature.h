// Name: ¤ý¥¿§»
// Date: March 29, 2022
// Last Update: March 13, 2022
// Problem statement: Observation Diary
#pragma once
#include"Diary.h"
typedef struct body_parts {
	string name;
	int amount = 0;
};

class Creature {
public:
	Creature() { name = ""; }
	Creature(string in_name);
	Creature(string in_name, Creature base);
	Creature& operator[](string in);
	Creature& operator=(int input);
	Creature& operator+=(int input);
	Creature& operator-=(int input);
	int operator+(int input);
	int operator-(int input);
	void PrintStatus();
	void PrintLog();
private:
	int index = 0;
	string name;
	int start_day_index;
	vector<body_parts> body;
};
