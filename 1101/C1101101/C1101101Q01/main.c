#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int limit, calc = 1, first = 0, second = 1;
    scanf_s("%d", &limit);
	if (limit < 0) {
		printf("\"Invalid input\"");
		return 0;
	}
	switch (limit) 
	{
		case 0:
			printf("0");
			break;
		case 1:
			printf("1");
			break;
		default:
			for (int i = 3; i <= limit; i++) {
				first = second;
				second = calc;
				calc = first + second;
			}
			printf("%d\n", calc);
			break;
	}
    return 0;
}