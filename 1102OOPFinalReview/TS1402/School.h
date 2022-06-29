#pragma once
#include <iostream>
#include <string>

using namespace std;

class School {
protected:
	string name;
	float studentAmount, studentAmountNextYear;
public:
	School();
	School(string, float);
	virtual void admissions(float amount);
	virtual void dropouts(float amount);
	virtual void transfer(float amount, School& toSchool);
	friend ostream& operator<<(ostream& os, const School& School);
};

class PrivateSchool : public School {
protected:
	bool hasDroped = false;
public:
	PrivateSchool();
	PrivateSchool(string, float);
	virtual void dropouts(float amount);
};

class PublicSchool : public School {
protected:
	float growing_rate = 0.05;
public:
	PublicSchool();
	PublicSchool(string, float);
	virtual void dropouts(float amount);
	void apply_growth();
};