// Name: ¤ý¥¿§»
// Date: March 28, 2022
// Last Update: March 13, 2022
// Problem statement: Prime Number
#include "PrimeNumber.h"

bool isPrimeNumber(int num) {
	int limit = 0;
	for (limit = (num != 1 ? 2 : 1); num % limit; limit++);
	return limit > 1 && limit == num;
}

int PrimeNumber::get() {
	return value;
}

PrimeNumber::PrimeNumber() {
	value = 1;
}

PrimeNumber::PrimeNumber(int _value) {
	value = _value;
}

PrimeNumber& PrimeNumber::operator++() {
	/*
		PrimeNumber p1, p2(13);	
		PrimeNumber a = ++p1;
		=> p1: change, a: change
		=> both are change, and return changed value
	*/
	do {
		value++;
	} while (!isPrimeNumber(value));
	return *this;
}

PrimeNumber PrimeNumber::operator++(int num) {
	/*
		PrimeNumber p2(13);	
		PrimeNumber b = p2++; 
		=> b: nothing, p2: change
		=> it only change self, and return original
	*/
	PrimeNumber result = *this; // copy self
	do {
		value++;
	} while (!isPrimeNumber(value));
	return result;
}

PrimeNumber& PrimeNumber::operator--() {
	if (value <= 2) {
		value = 1;
		return *this;
	}
	do {
		value--;
	} while (!isPrimeNumber(value));
	return *this;
}

PrimeNumber PrimeNumber::operator--(int num) {
	PrimeNumber result = *this;
	if (value <= 2) {
		value = 1;
		return result;
	}
	do {
		value--;
	} while (!isPrimeNumber(value));
	return result;
}