// Name: ¤ý¥¿§»
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: guess number
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
	double input, r, guess, cache;
	while (cin >> input)
	{
		//1.	Make a guess at the answer(you can pick n / 2 as your initial guess).
		guess = input / 2;
		do
		{
			cache = guess;
			//2.	Compute r = n / guess
			r = input / guess;
			//3.	Set guess = (guess + r) / 2.
			guess = (guess + r) / 2;
			//4.	Go back to step 2 for as many iterations as necessary.The more steps 2 and 3 are repeated, the closer guess will become to the square root of n.
		} while (abs(guess - cache) > 0.01);
		// print data
		std::cout << fixed << setprecision(2) << guess << endl;
	}
	return 0;
}