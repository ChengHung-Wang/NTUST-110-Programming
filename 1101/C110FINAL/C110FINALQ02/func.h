#pragma once
#include <stdio.h>
#include <stdlib.h>

int indexOf(const float find, float string[][2], int length) {
	for (int index = 0; index < length; index++) {
		if (string[index][0] == find) {
			return index;
		}
	}
	return -1;
}
// A structure represents the value of each point
struct point
{
    // Axis values of x and y
    float x, y;

    // Pointer to next point
    struct point* next;
};
int compare(struct point* a, struct point* b)
{
	float result = (a->x == b->x) ? (a->y - b->y) : (a->x - b->x);
	if (result == 0) {
		return 0;
	}
	return result < 0 ? -1 : 1;
}
/// <summary>
/// Convert the given point list into a linked list using 'point' structure.
/// </summary>
/// <param name="size">The size of list.</param>
/// <param name="data">The point list.</param>
/// <returns>The first node of the created linked list.</returns>
struct point* convert(int size, float data[][2])
{
	struct point* main = (struct student*)malloc(sizeof(struct point) * size);
	float *x = (float*)malloc(sizeof(size) + 1);
	float *y = (float*)malloc(sizeof(size) + 1), *config = (float*)malloc(sizeof(1));
	for (int i = 0; i < size; i++) {
		x[i] = data[i][0];
		y[i] = data[i][1];
		main->x = data[i][0];
		main->y = data[i][1];
		main++;
	}
	x[size] = '\0';
	qsort(main, size, sizeof(main), compare);
	for (int i = 0; i < size; i++) {
		printf("%.2f %.2f\n", main->x, main->y);

	}
	exit(0);
}

/// <summary>
/// Sort points in ascending order prioritizing on the x value.
/// </summary>
/// <param name="size">The first node of the linked list.</param>
/// <returns>The first node of the sorted linked list.</returns>
struct point* sort(struct point* list)
{
    
}
