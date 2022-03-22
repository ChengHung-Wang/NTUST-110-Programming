#pragma once

// The string length of name
#define LEN_NAME 50

// A structure represents the information of each student
struct student
{
    // The name string
    // Parameter: name (string)
    char name[LEN_NAME];

	// The score of English
	// Parameter: english (integer)
	int english;

	// The score of Math
	// Parameter: math (integer)
	int math;
    // The score of History
    // Parameter: history (integer)
	int history;
    // The score of Physics
    // Parameter: physics (integer)
	int physics;
    // Pointer to next student
    // Parameter: next (struct pointer)
	struct student* next;
};

/// <summary>
/// Convert the given CSV format string into a linked list using 'student' structure.
/// </summary>
/// <param name="data">The data string.</param>
/// <returns>The first node of the created linked list.</returns>
struct student* convert(char* data)
{
	for (int i = 0; i < sizeof(data); i++) {
		//while(*data[i])
	}
}

/// <summary>
/// Calculate the total score of each student, and return the average of all total scores.
/// </summary>
/// <param name="node">The starter node of linked list.</param>
/// <returns>The average value.</returns>
float average(struct student* node)
{
    
}
