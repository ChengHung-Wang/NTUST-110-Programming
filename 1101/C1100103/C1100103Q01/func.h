#pragma once
#include <stdlib.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#pragma warning(disable : 6011)
#include <stdio.h>
// The string length of name
#define LEN_NAME 50

// A structure represents the information of each student
struct student {
	// The name string
	// Parameter: name (string)
	char *name;

	// The score of English
	// Parameter: english (integer)
	int english;

	// The score of Math
	// Parameter: math (integer)

	int math;
	// Pointer to next student
	// Parameter: next (pointer)
	struct student *next;
};

/// <summary>
/// Convert the given 2 arrays into a linked list using 'student' structure.
/// </summary>
/// <param name="names">The name list.</param>
/// <param name="scores">The score list</param>
/// <returns>The first node of the created linked list.</returns>
struct student *convert(char names[][LEN_NAME], int scores[][2]) {
	struct student *first = (struct student *)malloc(sizeof(struct student));
	struct student *current = first;

	first->name = names[0];
	first->english = scores[0][0];
	first->math = scores[0][1];
	first->next = NULL;

	for (size_t i = 1; names[i][0] != '\0'; i++) {
		current->next = (struct student *)malloc(sizeof(struct student));
		current = current->next;
		current->name = names[i];
		current->english = scores[i][0];
		current->math = scores[i][1];
	}
	current->next = NULL;
	return first;
}