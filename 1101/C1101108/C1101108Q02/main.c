#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>
#include <math.h>

int convertBinaryToDecimal(char* s)
{
	int res = 0, i;
	char* p;
	i = 1;
	p = s;
	while (*p != '\0')p++;
	while (p != s) {
		p--;
		res = res + i * (*p - '0');
		i *= 2;
	}
	return res;
}

int gcd(int m, int n) {
	int t = 1;
	while (t != 0) {
		t = m % n;
		m = n;
		n = t;
	}
	return m;
}
int main()
{
	char a[32], b[32];
	int limit, number, calc, calcAfter, needLove = 0;
	scanf_s("%d ", &limit);
	for (int index = 0; index < limit; index++) {
		scanf("%s", a);
		scanf("%s", b);
		number = convertBinaryToDecimal(a);
		calc = convertBinaryToDecimal(b);
		calcAfter = gcd(number, calc);
		if (calcAfter == 1) {
			printf("Pair #%d: Love is not all you need!\n", index + 1);
		}
		else {
			printf("Pair #%d: All you need is love!\n", index + 1);
		}
	}
}