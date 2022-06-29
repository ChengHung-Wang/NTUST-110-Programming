#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class School {
public:
	string name;
	int studentNumber;
	int studentNumberNextYear;

	School(string name, int studentNumber) {
		this->name = name;
		this->studentNumber = studentNumber;
		this->studentNumberNextYear = studentNumber;
	}

	friend ostream& operator<<(ostream& os, const School& school) {
		os << school.name << "\t" << school.studentNumber << "\t" << school.studentNumberNextYear;
		return os;
	}

	void admissions(float number) {
		if (number < 0)
		{
			cout << "ERROR" << endl;
			return;
		}
		this->studentNumber += number;
	}

	virtual void dropouts(float number) {
		if (number < 0 || number > this->studentNumber)
		{
			cout << "ERROR" << endl;
			return;
		}
		this->studentNumber -= number;
	}

	void transfer(float number, School& toSchool) {
		if (number < 0 || number > this->studentNumber)
		{
			this->dropouts(number);
			return;
		}
		this->dropouts(number);
		toSchool.admissions(number);
	}

};

class PrivateSchool : public School {
public:
	PrivateSchool(string name, int studentNumber) : School(name, studentNumber) {

	}

	int dropouts_times = 0;

	void dropouts(float number) override {
		if (number < 0 || number > this->studentNumber || (this->dropouts_times + 1 > 1 && this->studentNumberNextYear < 100))
		{
			cout << "ERROR" << endl;
			return;
		}
		this->studentNumber -= number;
		this->dropouts_times += 1;
		if (dropouts_times > 1)
		{
			this->studentNumberNextYear -= 100;
		}
	}

};

class PublicSchool : public School {
public:
	PublicSchool(string name, int studentNumber) : School(name, studentNumber) {

	}
	float growing_rate = 0.05;

	void apply_growth() {
		this->studentNumberNextYear += growing_rate * this->studentNumberNextYear;
	}

	void dropouts(float number) override {
		if (number < 0 || number > this->studentNumber)
		{
			cout << "ERROR" << endl;
			return;
		}
		this->studentNumber -= number;
		if (number >= 100)
		{
			this->studentNumberNextYear *= 0.95;
		}
	}
};