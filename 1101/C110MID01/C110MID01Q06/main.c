#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	char num[100];
	scanf("%s", num);
	for (int now = 0; now < 100 - 1; now++) {
		int n = (int)num[now] - 48;
		int n2 = (int)num[now] - 48;
		if (n == 1 && n2 == 1) {
			printf("%s is a multiple of 11.\n", num);
			return 0;
		}
	}
	printf("%s is not a multiple of 11.\n", num);
	return 0;
}