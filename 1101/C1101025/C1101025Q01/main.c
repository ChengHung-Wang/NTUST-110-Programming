#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    int limit, arr[100];
    scanf("%d", &limit);
    for (int index = 0; index < limit; index++) {
        scanf("%d", &arr[index]);
    }
    qsort(arr, limit, sizeof(int), compare);
    for (int index = 0; index < limit; index++) {
        printf("%d%c", arr[index], index < (limit - 1) ? ' ' : '\n');
    }
}