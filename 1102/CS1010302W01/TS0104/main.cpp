// Name: ¤ý¥¿§»
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Input/Output 1
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	std::string input;
	while (cin >> input) {
		// pad string by space char
		std::cout << std::right << std::setw(10) << input << std::endl;
	}
	return 0;
}