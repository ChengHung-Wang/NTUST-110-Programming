#include <stdio.h>

int main()
{
	int input[2][4];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			scanf_s("%d", &input[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) {
		printf("%d%c", input[0][i] + input[1][i], i % 2 ? '\n' : ' ');
	}
}
