#include <stdio.h>

int main()
{
	int input[2][4];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			scanf_s("%d", &input[i][j]);
		}
	}
	
	// [0][0] [0][1]	[1][0] [1][1]
	// [0][2] [0][3]	[1][2] [1][3]

	//for (int i = 0; i < 4; i++) {
		//printf("%d%c", input[0][i] * input[1][i], i % 2 ? '\n' : ' ');
	//}
	printf("%d %d\n", input[0][0] * input[1][0] + input[0][1] * input[1][2], input[0][0] * input[1][1] + input[0][1] * input[1][3]);
	printf("%d %d", input[0][2] * input[1][0] + input[0][3] * input[1][2], input[0][2] * input[1][1] + input[0][3] * input[1][3]);
	return 0;
}
