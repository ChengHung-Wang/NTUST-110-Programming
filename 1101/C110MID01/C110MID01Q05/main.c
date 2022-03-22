#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int num[100][100], result[100][100], limit, size;
	scanf_s("%d", &limit);
	scanf_s("%d", &size);
	for (int index = 0; index < limit; index++) {
		for (int martixRow = 0; martixRow < size; martixRow ++) {
			for (int martixCol = 0; martixCol < size; martixCol++) {
				scanf_s("%d", &num[martixRow][martixCol]);
			}
		}

		for (int martixRow = 0; martixRow < size; martixRow++) {
			int cache = 0;
			for (int martixCol = 0; martixCol < size; martixCol++) {
				cache += num[martixRow][martixCol];
				printf("%d ", cache);
			}
			printf("\n");
		}
	}
	
    return 0;
}


/*
2
4
1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31
0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30*/

//#include <stdio.h>
//
//int main()
//{
//	int input[2][4];
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 4; j++) {
//			scanf_s("%d", &input[i][j]);
//		}
//	}
//	for (int i = 0; i < 4; i++) {
//		printf("%d%c", input[0][i] + input[1][i], i % 2 ? '\n' : ' ');
//	}
//}
