#include "PrimeNumber.h"

bool isPrimeNumber(int num) {
	int limit = 0;
	for (int limit = (num > 1 ? 2 : 1); num % limit; limit++);
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
	
}

PrimeNumber PrimeNumber::operator++(int) {

}

PrimeNumber& PrimeNumber::operator--() {

}

PrimeNumber PrimeNumber::operator--(int) {

}