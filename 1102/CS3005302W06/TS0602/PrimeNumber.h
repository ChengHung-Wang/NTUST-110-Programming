// Name: ¤ý¥¿§»
// Date: March 28, 2022
// Last Update: March 13, 2022
// Problem statement: Prime Number
class PrimeNumber {
public:
	int value;
	int get();
	PrimeNumber();
	PrimeNumber(int _value);
	PrimeNumber & operator++();
	PrimeNumber operator++(int);
	PrimeNumber & operator--();
	PrimeNumber operator--(int);
};