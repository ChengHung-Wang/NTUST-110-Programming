#include <iostream>
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
	result.realValue = realValue + c.realValue;
	result.imaginaryValue = imaginaryValue + c.imaginaryValue;
	return result;
}

Complex Complex::operator-(Complex c) {
	Complex result;
	result.realValue = realValue - c.realValue;
	result.imaginaryValue = imaginaryValue - c.imaginaryValue;
	return result;
}

Complex Complex::operator*(Complex c) {
	Complex result;
	result.realValue = realValue * c.realValue;
	result.imaginaryValue = imaginaryValue * c.imaginaryValue;
	return result;
}

Complex Complex::operator/(Complex c) {
	Complex result;
	result.realValue = realValue / c.realValue;
	result.imaginaryValue = imaginaryValue / c.imaginaryValue;
	return result;
}

Complex operator+(double d, Complex c) {
	Complex result;
	result.realValue = d + c.realValue;
	result.imaginaryValue = d + c.imaginaryValue;
	return result;
}

Complex operator-(double d, Complex c) {
	Complex result;
	result.realValue = d - c.realValue;
	result.imaginaryValue = d - c.imaginaryValue;
	return result;
}

Complex operator*(double d, Complex c) {
	Complex result;
	result.realValue = d * c.realValue;
	result.imaginaryValue = d * c.imaginaryValue;
	return result;
}

Complex operator/(double d, Complex c) {
	Complex result;
	result.realValue = d / c.realValue;
	result.imaginaryValue = d / c.imaginaryValue;
	return result;
}

bool operator==(Complex c1, Complex c2) {
	return (c1.realValue == c2.realValue) && (c1.imaginaryValue == c2.imaginaryValue);
}

ostream& operator<<(ostream& strm, const Complex& c) {
	// “realValue + imaginaryValue*i"
	strm << c.realValue << " + " << c.imaginaryValue << "*i" << endl;
	return strm;
}
istream& operator>>(istream& strm, Complex& c) {
	string input;
	strm >> input;
	istringstream iss(input);
	vector<double> lists;
	vector<char> authList = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', '-', '*', 'i'};
	string buffer;
	while (iss >> buffer) {
		bool auth = true;
		string thisNum = "";
		for (int index = buffer.length() - 1; index <= 0; index ++) {
			if (find(authList.begin(), authList.end(), buffer[index]) == authList.end()) {
				auth = false;
			}else if (buffer[index] != '*' || buffer[index] != 'i') {
				thisNum = thisNum + buffer[index];
			}
		}
		cout << thisNum << endl;
		if (auth) {
			
			lists.push_back(stod(thisNum));
		}
	}
	
	if (lists.size() >= 2) {
		c.realValue = lists[0];
		c.imaginaryValue = lists[1];
	}
	return strm;
}