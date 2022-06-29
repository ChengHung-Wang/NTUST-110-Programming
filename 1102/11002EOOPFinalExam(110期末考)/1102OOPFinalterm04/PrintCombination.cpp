#include "PrintCombination.h"

void PrintCombination(int* ptr, int size, int target)
{
	std::vector<bool> v(size, true);
	std::fill(v.begin() + target, v.end(), false);
	std::vector<std::vector<int>> output;

	std::vector<int> temp;
	for (int n = 0; n < size; n++)
	{
		if (v[n])temp.push_back(ptr[n]);
	}
	output.push_back(temp);

	while (std::prev_permutation(v.begin(), v.end()))
	{
		std::vector<int> temp;
		for (int n = 0; n < size; n++)
		{
			if (v[n])temp.push_back(ptr[n]);
		}
		output.push_back(temp);
	}

	for (const auto& k : output)
	{
		for (int n = 0; n < target - 1; n++) {
			std::cout << k[n] << ' ';
		}
		std::cout << k[target - 1] << '\n';
	}

}