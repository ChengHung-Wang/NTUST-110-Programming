// Name: ¤ý¥¿§»
// Date: April 16, 2022
// Last Update: April 16, 2022
// Problem statement: Design Polynomial Class
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Polynomial {
public:
	Polynomial();
	Polynomial(double*, int);
	Polynomial(const Polynomial&);

	vector<double> coefficients;
	// const ??
	int mySize() const;
	
	Polynomial& operator=(const Polynomial&);
	double& operator[](const unsigned int);

	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	friend Polynomial operator+(const double&, const Polynomial&);
	friend Polynomial operator+(const Polynomial&, const double&);
	
	friend Polynomial operator-(const Polynomial&, const Polynomial&);
	friend Polynomial operator-(const double&, const Polynomial&);
	friend Polynomial operator-(const Polynomial&, const double&);

	friend Polynomial operator*(const Polynomial&, const Polynomial&);
	friend Polynomial operator*(const double&, const Polynomial&);
	friend Polynomial operator*(const Polynomial&, const double&);

	friend double evaluate(const Polynomial&, double);
};