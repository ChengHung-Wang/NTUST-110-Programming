// Name: 王正宏
// Date: March 28, 2022
// Last Update: March 13, 2022
// Problem statement: Complex
#include <iostream>
#include <complex>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include "Complex.h"

Complex::Complex() {
	realValue = 0;
	imaginaryValue = 0;
}

Complex::Complex(double r) {
	realValue = r;
	imaginaryValue = 0;
}

Complex::Complex(double r, double i) {
	realValue = r;
	imaginaryValue = i;
}

double Complex::real() {
	return realValue;
}

double Complex::imag() {
	return imaginaryValue;
}

double Complex::norm() {
	return sqrt(pow(realValue, 2.0) + pow(imaginaryValue, 2.0));
}

double real(Complex c) {
	return c.realValue;
}

double imag(Complex c) {
	return c.imaginaryValue;
}

double norm(Complex c) {
	return sqrt(pow(c.realValue, 2.0) + pow(c.imaginaryValue, 2.0));
}

Complex Complex::operator+(Complex c) {
	Complex result;
	complex<double> calc(realValue, imaginaryValue);
	complex<double> calc2(c.realValue, c.imaginaryValue);
	calc += calc2;
	result.realValue = calc.real();
	result.imaginaryValue = calc.imag();
	return result;
}

Complex Complex::operator-(Complex c) {
	Complex result;
	complex<double> calc(realValue, imaginaryValue);
	complex<double> calc2(c.realValue, c.imaginaryValue);
	calc -= calc2;
	result.realValue = calc.real();
	result.imaginaryValue = calc.imag();
	return result;
}

Complex Complex::operator*(Complex c) {
	Complex result;
	complex<double> calc(realValue, imaginaryValue);
	complex<double> calc2(c.realValue, c.imaginaryValue);
	calc *= calc2;
	result.realValue = calc.real();
	result.imaginaryValue = calc.imag();
	return result;
}

Complex Complex::operator/(Complex c) {
	Complex result;
	complex<double> calc(realValue, imaginaryValue);
	complex<double> calc2(c.realValue, c.imaginaryValue);
	calc /= calc2;
	result.realValue = calc.real();
	result.imaginaryValue = calc.imag();
	return result;
}

Complex operator+(double d, Complex c) {
	Complex result;
	complex<double> calc(c.realValue, c.imaginaryValue);
	calc = d + calc;
	result.realValue = calc.real();
	result.imaginaryValue = calc.imag();
	return result;
}

Complex operator-(double d, Complex c) {
	Complex result;
	complex<double> calc(c.realValue, c.imaginaryValue);
	calc = d - calc;
	result.realValue = calc.real();
	result.imaginaryValue = calc.imag();
	return result;
}

Complex operator*(double d, Complex c) {
	Complex result;
	complex<double> calc(c.realValue, c.imaginaryValue);
	calc = d * calc;
	result.realValue = calc.real();
	result.imaginaryValue = calc.imag();
	return result;
}

Complex operator/(double d, Complex c) {
	Complex result;
	complex<double> calc(c.realValue, c.imaginaryValue);
	calc = d / calc;
	result.realValue = calc.real();
	result.imaginaryValue = calc.imag();
	return result;
}

bool operator==(Complex c1, Complex c2) {
	return (c1.realValue == c2.realValue) && (c1.imaginaryValue == c2.imaginaryValue);
}

ostream& operator<<(ostream& strm, const Complex& c) {
	// “realValue + imaginaryValue*i"
	strm << c.realValue << " + " << c.imaginaryValue << "*i";
	return strm;
}
istream& operator>>(istream& strm, Complex& c) {
	string input;
	vector<double> lists;
	vector<char> authList = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', '-', '*', 'i' };

	for (int index = 0; index < 5; index++) {
		strm >> input;
		if (index == 2 || index == 4) {
			bool auth = true;
			string thisNum = "";

			for (int index2 = input.length() - 1; index2 >= 0; index2--) {
				if (find(authList.begin(), authList.end(), input[index2]) == authList.end()) {
					auth = false;
				}
				else if (input[index2] != '*' && input[index2] != 'i') {
					thisNum = thisNum + input[index2];
				}
			}
			if (auth) {
				lists.push_back(stod(thisNum));
			}
		}
	}
	
	if (lists.size() >= 2) {
		c.realValue = lists[0];
		c.imaginaryValue = lists[1];
	}

	return strm;
}