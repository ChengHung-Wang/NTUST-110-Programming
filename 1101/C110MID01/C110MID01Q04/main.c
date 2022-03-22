#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int first[8][8], second[8][8], size;
	scanf_s("%d", &size);
	for (int rowIndex = 0; rowIndex < size; rowIndex++) {
		for (int colIndex = 0; colIndex < size; colIndex++) {
			scanf_s("%d", &first[rowIndex][colIndex]);
		}
	}
	for (int rowIndex = 0; rowIndex < size; rowIndex++) {
		for (int colIndex = 0; colIndex < size; colIndex++) {
			scanf_s("%d", &second[rowIndex][colIndex]);
		}
	}
	/*for (int now = 0; now < size; now++) {
		for (int colIndex = 0; colIndex < size; colIndex++) {
			int cache = 0;
			for (int rowIndex2 = 0; rowIndex2 < size; rowIndex2++) {
				printf("first[%d][%d] * second[%d][%d]\n", now, colIndex, rowIndex2, colIndex);
				cache += first[now][colIndex] * second[rowIndex2][colIndex];
			}
		}
		printf("\n");
	}*/
	for (int rowIndex = 0; rowIndex < size; rowIndex++) {
		int cache = 0;
		for (int colIndex = 0; colIndex < size; colIndex++) {
			cache += first[rowIndex][colIndex] * second[rowIndex][colIndex];
			// printf("first[%d][%d] * second[%d][%d]\n", rowIndex, colIndex, colIndex, rowIndex);
		}
		printf("%d ", cache);
	}
}


/*
2
4
1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31
0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
*/