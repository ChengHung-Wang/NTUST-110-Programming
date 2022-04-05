// Name: ¤ý¥¿§»
// Date: March 29, 2022
// Last Update: March 13, 2022
// Problem statement: N Dim Vector
#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class VecNf {
public:
	VecNf();
	VecNf(float*, int);
	VecNf(const VecNf&);
	~VecNf();
	VecNf operator+(VecNf const&);
	VecNf operator-(VecNf const&);
	float operator*(VecNf const&);
	VecNf& operator=(const VecNf&);
	float& operator[](int);
	VecNf operator*(double);
	friend VecNf operator*(double, VecNf&);
	int Size();
private:
	float* element = nullptr;
	int cnt = 1;
};