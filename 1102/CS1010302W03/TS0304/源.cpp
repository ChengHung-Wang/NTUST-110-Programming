// Name: ¤ý¥¿§»
// Date: March 03, 2022
// Last Update: March 03, 2022
// Problem statement: Input_Output3
#include <iostream>

using namespace std;

int main1() {
	unsigned long ans[31] = { 3 }, inp;
	double nLog = log10(6), kLog;
	
	for (unsigned long i = 1, n = 3, k = 4; i < 31; i++) {
		k <<= 1;
		kLog = log10(2) * (double)k;
		while (nLog < kLog) {
			n++;
			nLog += log10(n);
		}
		ans[i] = n - 1;
	}
	while (std::cin >> inp) {
		std::cout << ans[(inp - 1900) / 10] << endl;
	}
}