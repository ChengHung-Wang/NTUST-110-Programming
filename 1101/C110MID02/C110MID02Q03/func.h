#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// <summary>
/// Apply Caesar cipher to the message.
/// </summary>
/// <param name="msg">The message string for encryption.</param>
/// <param name="shift">The shift amount.</param>
void caesar_cipher(char *msg, int shift)
{
	const int len = strlen(msg);
	const newShift = shift % 26;
	char buffer[1000];
	int bufferIndex = 0;
	for (int index = 0; index < len; index++) {
		if ((*msg >= 'A' && *msg <= 'Z') || (*msg >= 'a' && *msg <= 'z')) {
			if ((*msg >= 'A' && *msg <= 'Z')) {
				
				if (*msg + newShift > 'Z') {
					buffer[bufferIndex] = (*msg + newShift) - 'Z' + 'A' - 1;
				}
				else if (*msg + newShift < 'A') {
					buffer[bufferIndex] = (*msg + newShift) + 'Z' - 'A' + 1;
				}
				else {
					buffer[bufferIndex] = (*msg + newShift);
				}
			}
			if ((*msg >= 'a' && *msg <= 'z')) {
				if (*msg + newShift > 'z') {
					buffer[bufferIndex] = (*msg + newShift) - 'z' + 'a' - 1;
				}
				else if (*msg + newShift < 'a'){
					buffer[bufferIndex] = (*msg + newShift) + 'z' - 'a' + 1;
				}
				else {
					buffer[bufferIndex] = (*msg + newShift);
				}
			}
			bufferIndex++;
		}
		else {
			buffer[bufferIndex] = *msg;
			bufferIndex++;
		}
		msg++;
	}
	buffer[bufferIndex++] = '\0';
	printf("%s\n", buffer);
	//char **msg = &buffer;
}

/// <summary>
/// Print the result.
/// </summary>
/// <param name="msg">A message string.</param>
void print_result(char msg)
{
	return;
	//printf("%s\n", msg);
}



//Hello world!
//4
//
//Lipps asvph!