#include "Month.h"
#include <iostream>
#include <string>

using namespace std;

string month_string[12] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

Month::Month()
{
	month = 1;
}

Month::Month(char first, char second, char third)
{
	string str = "";
	bool valid = false;
	str = str + first + second + third;
	for (int i = 0; i < 12; i++) {
		if (month_string[i] == str) {
			month = i + 1;
			valid = true;
			break;
		}
	}
	if (! valid) {
		month = 1;
	}
}

Month::Month(int monthInt)
{
	if (monthInt < 1 || monthInt > 12) {
		month = 1;
	}
	else {
		month = monthInt;
	}
}


Month::~Month()
{
}

void Month::inputInt()
{
	int num;
	cin >> num;
	if (num < 1 || num > 12) {
		month = 1;
	}
	else {
		month = num;
	}
}

void Month::inputStr()
{
	char input[3];
	cin >> input[0];
	cin >> input[1];
	cin >> input[2];
	string  str = "";
	str = str + input[0] + input[1] + input[2];
	bool valid = false;
	for (int i = 0; i < 12; i++) {
		if (month_string[i] == str) {
			month = i + 1;
			valid = true;
			break;
		}
		
	}
	if (!valid) {
		month = 1;
	}
}

void Month::outputInt()
{
	cout << to_string(month);
}

void Month::outputStr()
{
	cout << month_string[month - 1];
}

Month Month::nextMonth()
{
	if (month >= 12) {
		return Month(1);
	}
	else {
		return Month(month + 1);
	}
	
}
