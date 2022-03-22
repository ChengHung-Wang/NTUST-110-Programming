// Name: ¤ý¥¿§»
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Compute Sphere Volume
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Compute Sphere Volume function
double calc(double radius) {
	double pi = 3.14159265358979323846;
	return 4.0 / 3.0 * pi * radius * radius * radius;
}
int main() {
	double input;
	while (cin >> input) {
		// format
		std::cout << std::fixed << setprecision(6) << calc(input) << "\n";
	}
	return 0;
}