#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
int toNumber(string);
int main() {
	char a[] = "123123";
	string result = string(15 - strlen(a), '0').append(a);
	cout << result << endl;
	int limit;
	while (cin >> limit) {
		cout << "COWCULATIONS OUTPUT" << endl;
		for (int round = 0; round < limit; limit++) {
			string num1, num2;
			cin >> num1 >> num2;
			int intNum1 = toNumber(num1);
			int intNum2 = toNumber(num2);
			
			for (int i = 0; i < 3; i++) {
				char method;
				cin >> method;
				if (method == 'A') {
					intNum2 = intNum1 + intNum2;
				}
				else if (method == 'L') {
					intNum2 *= 4;
				}
				else if (method == 'R') {
		 			intNum2 /= 4;
				}
			}
			string result;
			cin >> result;
			int resultInt = toNumber(result);
			cout << ((resultInt == intNum2) ? "YES" : "NO") << endl;
		}
		cout << "END OF OUTPUT" << endl;
	}
	return 0;
}

int toNumber(string input) {
	int result = 0;
	map<char, int> addConfig;
	addConfig['V'] = 0;
	addConfig['U'] = 1;
	addConfig['C'] = 2;
	addConfig['D'] = 3;
	for (char& item : input) {
		result = (result * 4) + addConfig[item];
	}
	return result;
}