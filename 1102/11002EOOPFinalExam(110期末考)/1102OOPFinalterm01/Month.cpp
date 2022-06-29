#include "Month.h"
vector<string> monthConfig = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
Month::Month()
{
	month = 1;
}

Month::Month(char first, char second, char third)
{
	int index = 0;
	bool hasFind = false;
	first = toupper(first);
	for (const string& item : monthConfig) {
		if (!hasFind) {
			if (item[0] == first && item[1] == second && item[2] == third) {
				month = index + 1;
				hasFind = true;
			}
		}
		index++;
	}
	if (!hasFind) {
		month = 1;
	}
}

Month::Month(int monthInt)
{
	if (monthInt <= 12 && monthInt >= 1) {
		month = monthInt;
	}
	else {
		month = 1;
	}
}


Month::~Month()
{
}

void Month::inputInt()
{
	int input;
	cin >> input;
	if (input <= 12 && input >= 1) {
		month = input;
	}
	else {
		month = 1;
	}
}

void Month::inputStr()
{
	char first, second, third;
	cin >> first >> second >> third;
	int index = 0;
	first = toupper(first);
	bool hasFind = false;
	for (const string& item : monthConfig) {
		if (!hasFind) {
			if (item[0] == first && item[1] == second && item[2] == third) {
				month = index + 1;
				hasFind = true;
			}
		}
		index++;
	}
	if (!hasFind) {
		month = 1;
	}
}

void Month::outputInt()
{
	cout << to_string(month);
}

void Month::outputStr()
{
	cout << monthConfig[month - 1];
}

Month Month::nextMonth()
{
	Month result = Month(this->month);
	if (result.month < 12 && result.month >= 1) {
		result.month++;
	}
	else {
		result.month = 1;
	}
	return result;
}
