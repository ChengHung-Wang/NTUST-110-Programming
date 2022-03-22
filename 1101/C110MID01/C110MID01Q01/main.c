#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int limit;
	scanf_s("%d", &limit);
	if (limit <= 2 || limit > 20) {
		printf("Invalid input\n");
		return 0;
	}
	for (int line = limit - 1; line > 0; line--)
	{
		// whitespace
		for (int i = limit - 1 - line; i > 0; i--)
		{
			putchar(' ');
		}

		// character
		for (int i = 0; i < line * 2 + 1; i++)
		{
			putchar('*');
		}

		putchar('\n');
	}
	for (int line = 0; line < limit; line++)
	{
		// whitespace
		for (int i = 0; i < limit - 1 - line; i++)
		{
			putchar(' ');
		}

		// character
		for (int i = 0; i < line * 2 + 1; i++)
		{
			putchar('*');
		}

		putchar('\n');
	}
	
}