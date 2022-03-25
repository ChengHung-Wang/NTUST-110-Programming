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

}
istream& operator>>(istream& strm, Complex& c) {

}

Complex::~Complex() {}