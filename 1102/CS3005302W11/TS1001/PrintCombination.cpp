// Name: ¤ý¥¿§»
// Date: May 3, 2022
// Last Update: May 3, 2022
// Problem statement: Combinations
#include "PrintCombination.h"

void PrintCombination(int* arr, const int& combinationNum, const int& dlementNum)
{
	static bool init = false;
	if (!init) 
	{
		int* preStore = new int[combinationNum];
		for (int i = 0; i < combinationNum; i++) 
		{
			preStore[i] = arr[i];
		}
		init = true;
		for (int i = dlementNum; i < combinationNum; i++)
		{
			arr[i] = 0;
		}
		arr[combinationNum - 1] = -87;
		PrintCombination(arr, dlementNum, dlementNum - 1);
		init = false;
		for (int i = 0; i < combinationNum; i++) 
		{
			arr[i] = preStore[i];
		}
		delete[] preStore;
		return;
	}
	int maxNum = 0, maxIndex = -1;
	for (int i = 0; true; i++) 
	{
		if (arr[i] <= 0 && maxIndex == -1)
		{
			maxIndex = i - 1;
		}
		if (arr[i] == -87) 
		{
			maxNum = i + 1;//5
			break;
		}
	}
	for (int i = maxIndex; i >= dlementNum; i--)
	{
		arr[i] = combinationNum + (i - dlementNum);//3 4
		if (arr[i] > (i + maxNum - maxIndex))
		{
			if (dlementNum == 0)
			{ // err handle
				return;
			}
			PrintCombination(arr, arr[dlementNum - 1] + 1, dlementNum - 1);
			return;
		}
	}
	for (int i = 0; i <= maxIndex; i++)
	{
		string prefix = i == 0 ? "" : " ";
		cout << prefix << arr[i];
	}
	cout << endl;
	PrintCombination(arr, arr[maxIndex] + 1, maxIndex);
}