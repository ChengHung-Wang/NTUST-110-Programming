// Name: 王正宏
// Date: May 10, 2022
// Last Update: May 10, 2022
// Problem statement: Matrix Multiplication
#include <iostream> // c++ io
#include <string> // c++ string type
#include <map> // c++ like php key-value array
#include <vector> // c++ like js/php dynamic array

using namespace std;

int main() {
	int matrixArow, matrixAmajor, matrixBrow, matrixBmajor;
	vector<vector<int>> matrixA, matrixB;
	cin >> matrixArow >> matrixAmajor >> matrixBrow >> matrixBmajor;
	if (matrixAmajor != matrixBrow) {
		cout << "Matrix multiplication failed." << endl;
		return 0;
	}
	// first line, enter matrixA info
	for (int row = 0; row < matrixArow; row++) 
	{
		vector<int> cache;
		for (int col = 0; col < matrixAmajor; col++) 
		{
			int thisNum;
			cin >> thisNum;
			cache.push_back(thisNum);
		}
		matrixA.push_back(cache);
	}
	// second line, enter matrixB info
	for (int row = 0; row < matrixBrow; row++)
	{
		vector<int> cache;
		for (int col = 0; col < matrixBmajor; col++)
		{
			int thisNum;
			cin >> thisNum;
			cache.push_back(thisNum);
		}
		matrixB.push_back(cache);
	}
	// calc the result => matrixC
	int matrixCrow = matrixArow;
	int matrixCmajor = matrixBmajor;
	vector<vector<int>> matrixC;
	for (int row = 0; row < matrixCrow; row++) 
	{
		vector<int> thisLine;
		for (int col = 0; col < matrixCmajor; col++)
		{
			int cache = 0;
			for (int step = 0; step < matrixAmajor; step++)
			{
				cache += matrixA[row][step] * matrixB[step][col];
			}
			cout << cache;
			if (col < matrixCmajor - 1) {
				cout << " ";
			}
			thisLine.push_back(cache);
		}
		matrixC.push_back(thisLine);
		cout << "\n";
	}
	return 0;
}


//3 2 2 3
//1 2 3 4 5 6
//6 5 4 3 2 1

//12 654
//34 123
//56 