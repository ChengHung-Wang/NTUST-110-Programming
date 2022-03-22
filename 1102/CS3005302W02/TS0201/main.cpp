// Name: ¤ý¥¿§»
// Date: February 22, 2022
// Last Update: February 22, 2022
// Problem statement: Computes the average and standard deviation
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int limit;
	while (std::cin >> limit) {
		double total = 0, ave;
		vector<double> cache;
		for (int index = 0; index < limit; index++) {
			double input;
			std::cin >> input;
			cache.push_back(input);
			total += input;
		}
		ave = total / limit;
		double aveTotal = 0;
		for (int index = 0; index < cache.size(); index++) {
			aveTotal += (cache[index] - ave) * (cache[index] - ave);
		}
		std::cout << "Average:" << ave << "\tStandard deviation:" << sqrt(aveTotal / limit) << "\n";
	}
	return 0;
}