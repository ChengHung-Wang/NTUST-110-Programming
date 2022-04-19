// Name: 王正宏
// Date: April 16, 2022
// Last Update: April 16, 2022
// Problem statement: Design Polynomial Class
#include "Polynomial.h"

Polynomial::Polynomial() {
	coefficients = {};
}

Polynomial::Polynomial(double* list, int size) {
	coefficients = vector<double>(list, list + size);
}

Polynomial::Polynomial(const Polynomial& polynomial) {
	coefficients = polynomial.coefficients;
}

int Polynomial::mySize() const {
	for (int index = coefficients.size() - 1; index >= 0; index--) {
		if (coefficients[index] != 0) {
			return index + 1;
		}
	}
	return 0;
}

Polynomial& Polynomial::operator=(const Polynomial& polynomial) {
	coefficients = polynomial.coefficients;
	return *this;
}

double& Polynomial::operator[](const unsigned int index) {
	while (index > coefficients.size() - 1) {
		coefficients.push_back(0);
	}
	return coefficients[index];
}

// plus
Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
	Polynomial result;
	int p1Size = p1.coefficients.size();
	int p2Size = p2.coefficients.size();

	for (int index = 0; index < max(p1Size, p2Size); index++) {
		int cache = 0;
		if (index < p1Size) {
			cache += p1.coefficients[index];
		}
		if (index < p2Size) {
			cache += p2.coefficients[index];
		}
		result.coefficients.push_back(cache);
	}

	return result;
}

Polynomial operator+(const double& num1, const Polynomial& p2) {
	Polynomial result = p2;
	if (p2.coefficients.size() == 0) {
		result.coefficients.push_back(num1);
	}
	else {
		result.coefficients[0] += num1;
	}
	return result;
}

Polynomial operator+(const Polynomial& p1, const double& num2) {
	Polynomial result = p1;
	if (p1.coefficients.size() == 0) {
		result.coefficients.push_back(num2);
	}
	else {
		result.coefficients[0] += num2;
	}
	return result;
}

// mius
Polynomial operator-(const Polynomial& p1, const Polynomial& p2) {
	Polynomial result;
	int p1Size = p1.coefficients.size();
	int p2Size = p2.coefficients.size();

	for (int index = 0; index < max(p1Size, p2Size); index++) {
		int cache = 0;
		if (index < p1Size) {
			cache += p1.coefficients[index];
		}
		if (index < p2Size) {
			cache -= p2.coefficients[index];
		}
		result.coefficients.push_back(cache);
	}

	return result;
}

// number - Polynomial
Polynomial operator-(const double& num1, const Polynomial& p2) {
	Polynomial result = p2;
	for (auto& item : result.coefficients) {
		item *= -1;
	}
	if (p2.coefficients.size() == 0) {
		result.coefficients.push_back(num1);
	}
	else {
		result.coefficients[0] += num1;
	}
	return result;
}

// Polynomial - number
Polynomial operator-(const Polynomial& p1, const double& num2) {
	Polynomial result = p1;
	if (p1.coefficients.size() == 0) {
		result.coefficients.push_back(-num2);
	}
	else {
		result.coefficients[0] -= num2;
	}
	return result;
}

// times
Polynomial operator*(const Polynomial& p1, const Polynomial& p2) {
	Polynomial result;
	int p1Size = p1.coefficients.size();
	int p2Size = p2.coefficients.size();
	result.coefficients = vector<double>(p1Size + p2Size - 1, 0);

	for (int i = 0; i < p1Size; i++)
	{
		for (int j = 0; j < p2Size; j++)
		{
			result[i + j] += p1.coefficients[i] * p2.coefficients[j];
		}
	}

	return result;
}

Polynomial operator*(const double& num1, const Polynomial& p2) {
	Polynomial result = p2;
	for (auto& item : result.coefficients) {
		item *= num1;
	}
	return result;
}

Polynomial operator*(const Polynomial& p1, const double& num2) {
	Polynomial result = p1;
	for (auto& item :  result.coefficients) {
		item *= num2;
	}
	return result;
}

double evaluate(const Polynomial& polynomial, double num) {
	double result = 0;
	int index = 0;
	for (const double& item : polynomial.coefficients) {
		int scale = 1;
		for (int round = 0; round < index; round++) {
			scale *= num;
		}
		result += (scale * polynomial.coefficients[index]);
		index++;
	}
	if (result == 661) {
		for (auto& item : polynomial.coefficients) {
			cout << item << " ";
		}
		cout << endl;
	}
	return result;
}