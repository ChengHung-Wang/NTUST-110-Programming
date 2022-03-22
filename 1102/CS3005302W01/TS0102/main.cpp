// Name: ¤ý¥¿§»
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Parser Datetime
#include <iostream>
#include <string>
using namespace std;
/*
 * This namespace is part of this work.
 *
 * (c) Wang-Cheng,Hung <b11015020@mail.ntust.edu.tw>
 *
 * For the full copyright and license information, please view the 
 * https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/customizing-your-repository/licensing-a-repository
 */
namespace datetime {
	class Parse {
	public:
		// to compute hours form second
		unsigned long long int hour(const unsigned long long config);
		// to compute minutes form second
		unsigned long long int min(const unsigned long long config);
		// to compute seconds form second
		unsigned long long int sec(const unsigned long long config);
	private:
		const unsigned long long step = 60;
	};
	unsigned long long Parse::hour(const unsigned long long config) 
	{
		// code for to compute hours form second
		return config / (step * step);
	}
	unsigned long long Parse::min(const unsigned long long config) 
	{
		// code for to compute minutes form second
		return (config - (step * step * hour(config))) / step;
	}
	unsigned long long Parse::sec(const unsigned long long config)
	{
		// code for to compute seconds form second
		return config - (step * step * hour(config)) - (step * min(config));
	}
}
int main() 
{
	unsigned long long input;
	static datetime::Parse carbon;
	// readline & process until EOF
	while (std::cin >> input)
	{
		std::cout << carbon.hour(input) << " hours "; // calc hours
		std::cout << carbon.min(input) << " minutes and "; // calc minutes
		std::cout << carbon.sec(input) << " seconds" << std::endl; // calc seconds
	}
	return 0;
}