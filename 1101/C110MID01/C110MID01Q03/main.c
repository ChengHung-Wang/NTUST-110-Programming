#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int num[10], repeat[100], find = 0, sum = 0;
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &num[i]);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i != j) {
				if (num[i] == num[j]) {
					int ok = 1;
					for (int index = 0; index < find; index++) {
						if (num[i] == repeat[index]) {
							ok = 0;
						}
					}
					if (ok == 1) {
						repeat[find] = num[i];
						find++;
					}
				}
			}
		}
	}
	for (int now = 0; now < find; now++) {
		sum += repeat[now];
	}
	printf("%d\n", sum);
}