#pragma once
#include "School.h"

School::School()
{
	name = "";
	studentAmount = 0;
	studentAmountNextYear = 0;
}

School::School(string _name, float amount)
{
	name = _name;
	studentAmount = amount;
	studentAmountNextYear = amount;
}


void School::admissions(float amount)
{
	if (amount >= 0)
	{
		studentAmount += amount;
	}
}

void School::dropouts(float amount)
{
	if (amount <= studentAmount && amount >= 0)
	{
		studentAmount -= amount;
	}
}

void School::transfer(float amount, School& toSchool)
{
	if (amount >= 0 && amount < studentAmount)
	{
		dropouts(amount);
		toSchool.admissions(amount);
	}
}

ostream& operator<<(ostream& os, const School& School)
{
	os << School.name << "\t" << School.studentAmount << "\t" << School.studentAmountNextYear;
	return os;
}

// private school
PrivateSchool::PrivateSchool() : School()
{}

PrivateSchool::PrivateSchool(string _name, float _amount) : School(_name, _amount)
{}

void PrivateSchool::dropouts(float amount)
{
	if (amount > 0 && amount <= studentAmount)
	{
		studentAmount -= amount;
		if (hasDroped)
		{
			studentAmountNextYear -= 100;
		}else
		{
			hasDroped = true;
		}
	}
}

// public school
PublicSchool::PublicSchool() : School()
{}

PublicSchool::PublicSchool(string _name, float _amount) : School(_name, _amount)
{}

void PublicSchool::apply_growth()
{
	studentAmountNextYear += (int)(growing_rate * studentAmountNextYear);
}
void PublicSchool::dropouts(float amount)
{
	if (amount <= studentAmount && amount > 0)
	{
		if (amount > 100)
		{
			studentAmountNextYear -= (int)(studentAmountNextYear * 0.05);
		}
		studentAmount -= amount;
	}
}
