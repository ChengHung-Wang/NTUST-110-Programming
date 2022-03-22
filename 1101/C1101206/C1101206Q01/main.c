// Given a roman numeral, convert it to an integer.

#include <stdio.h>
#include <stdlib.h>

char* ask(const char* prompt) {
	char c, * input;
	input = (char*)malloc(sizeof(*input));  // allocate 1 byte
	size_t index = 0;

	fputs(prompt, stdout);  // display the prompt

	// get a char `c`, check `c` is nither EOF nor '\n'
	while ((c = getchar()) != EOF && c != '\n') {
		input = (char*)realloc(input, index + 1);
		if (!input) {
			// allocation failed and input is NULL
			return input;
		}
		input[index++] = c;
	}
	input[index] = '\0';  // end the string with '\0'
	return input;
}

unsigned int value(char roman) {
	switch (roman) {
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	}
	return 0;
}

unsigned int roman_as_int(char* roman) {
	unsigned int result = 0;
	while (*roman != '\0') {
		const unsigned int curr = value(*roman),
						   next = value(*(roman + 1));
		if (curr >= next) {
			result += curr;
		}
		else {
			result += next - curr;
			roman++;
		}
		roman++;
	}
	return result;
}

int main() {
	printf("%d\n", roman_as_int(ask("")));
}