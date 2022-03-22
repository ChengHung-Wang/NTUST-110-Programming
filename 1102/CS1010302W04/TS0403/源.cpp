// Name: ¤ý¥¿§»
// Date: March 13, 2022
// Last Update: March 13, 2022
// Problem statement: Greatest Common Divisor
#include <iostream>
#include <string>

using namespace std;

static int hcf(int a, int b);

static int hcf(int a, int b) {
	if (b) {
		return hcf(b, a % b);
	}
	else {
		return a;
	}
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		cout << to_string(hcf(a, b)) << endl;
	}
}