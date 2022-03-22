#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdbool.h>
char* ask(const char* prompt) {
	char c, * input;
	input = (char*)malloc(sizeof(*input));  // allocate 1 byte
	size_t index = 0;

	fputs(prompt, stdout);  // display the prompt

	// get a char `c`, check `c` is nither EOF nor '\n'
	while ((c = getchar()) != EOF && c != '\n') {
		if (!(input = (char*)realloc(input, index + 1))) {
			// allocation failed and input is NULL
			return input;
		}

		input[index++] = c;
	}
	input[index] = '\0';  // end the string with '\0'

	return input;
}
void print(char* data, int height) {
	bool first = true, hasprint = false;
	while (*data != '\0') {
		int thisHeight = (*data) - '0';
		for (int i = 1; i <= thisHeight; i++) {
			if (i % 2 != 0) {
				// i < n - 1 - line
				if (i != 1 || !hasprint) {
					for (int s = 0; s < ((int)height - i) / 2; s++) {
						printf("%s", " ");
					}
					hasprint = true;
				}
				for (int j = i; j > 0; j--) {
					if (i == 1) {
						if (first) {
							first = false;
							printf("%d", i);
							printf("\n");
						}
					}
					else {
						printf("%d", i);
					}

				}
				if (i != 1) {
					printf("\n");
				}
			}
		}

		for (int i = thisHeight - 1; i >= 1; i--) {
			if (i % 2 != 0) {		
				for (int s = 0; s < (int)(height - i) / 2; s++) {
					printf("%s", " ");
				}
				for (int j = i; j > 0; j--) {
					printf("%d", i);
				}
				printf("\n");
			}
		}
		data++;
	}
}
int main()
{
	char str[1000];
	char* count = str;
	scanf("%s", str);
	int height = 0;
	while (*count != '\0') {
		if ((*count) - '0' > height) {
			height = (*count) - '0';
		}
		count++;
	}
	print(str, height);
	return 0;
}