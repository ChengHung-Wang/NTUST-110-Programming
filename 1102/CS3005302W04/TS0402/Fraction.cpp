// Name: ¤ý¥¿§»
// Date: March 13, 2022
// Last Update: March 13, 2022
// Problem statement: Fraction
#include "Fraction.h"
#include <iostream>
#include<sstream> 
#include <string>

using namespace std;

static bool isInt(double);
static int hcf(int a, int b);

void Fraction::setNumerator(int nu)
{
	Fraction::numerator = nu;
}

void Fraction::setDenominator(int de)
{
	Fraction::denominator = de;
}

void Fraction::getDouble()
{
	double result = (double)numerator / (double)denominator;
	stringstream stream;
	stream.precision(6);
	stream << fixed;
	stream << result;
	if (isInt(result)) {
		printf("%d\n", (int)result);
	}
	else {
		cout << stream.str() << endl;
	}
}

void Fraction::outputReducedFraction()
{
	int x = hcf(Fraction::numerator, Fraction::denominator);
	std::cout << Fraction::numerator / x;
	if (Fraction::denominator / x != 1) {
		std::cout << "/" << (Fraction::denominator / x);
	}
	std::cout << std::endl;
}

static bool isInt(double num) {
	string strNum = to_string(num);
	char splitBy = '.';
	bool isFind = false;
	for (auto& item : to_string(num)) {
		if (item == splitBy) {
			isFind = true;
		}
		else {
			if (isFind) {
				return item == '0';
			}
		}
	}
}

static int hcf(int a, int b) {
	if (b) {
		return hcf(b, a % b);
	}
	else {
		return a;
	}
}