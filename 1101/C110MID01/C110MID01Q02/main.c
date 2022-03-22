#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include "main.h"

int main()
{
	int arr[100], find = 0, pass = 0, num;
	scanf_s("%d", &num);
	for (int now = num - 1; now > 1; now--) {
		if (num % now == 0) {
			int ok = 1;
			for (int check = 2; check <= now - 1; check ++) {
				if (now % check == 0) {
					ok = 0;
				}
			}
			if (ok == 1) {
				arr[find] = now;
				find++;
			}
		}
	}
	if (num == 1) {
		printf("It is an ugly number.\n");
		return 0;
	}
	if (
		num != 2 && num != 3 && num != 5 &&
		find == 0
	) {
		printf("It is not an ugly number.\n");
		return 0;
	}
	else {
		for (int index = 0; index < find; index++) {
			// printf("%d\n", arr[index]);
			if (arr[index] != 2 && arr[index] != 3 && arr[index] != 5) {
				pass = 1;
			}
		}
		if (pass == 0) {
			printf("It is an ugly number.\n");
			return 0;
		}
		else {
			printf("It is not an ugly number.\n");
			return 0;
		}
	}
	
}