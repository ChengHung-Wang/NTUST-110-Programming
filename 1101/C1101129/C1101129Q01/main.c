#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int stepPosition;
	char input[BUFSIZ], cache;
	fgets(input, BUFSIZ, stdin);
	scanf_s("%d", &stepPosition);
	stepPosition %= 26;

	const size_t strLastIndex = strlen(input) - 1;
	input[strLastIndex] = '\0';
	for (int index = 0; input[index] != '\0'; index++) {
		cache = input[index];
		if (cache >= 'a' && cache <= 'z') {
			cache += stepPosition;
			if (cache > 'z') {
				cache = cache - 'z' + 'a' - 1;
			}
			input[index] = cache;
		}
		else if (cache >= 'A' && cache <= 'Z') {
			cache += stepPosition;
			if (cache > 'Z') {
				cache = cache - 'Z' + 'A' - 1;
			}
			input[index] = cache;
		}
	}
	printf("%s", input);
}