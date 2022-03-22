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
    // for i in len(arr) {
    //     newArr[i] = arr[rand(len(arr))]
    // }
    int limit, arr[100], repeatNums[100], repeatCount = 0;
    scanf("%d", &limit);
    for (int index = 0; index < limit; index++) {
        scanf("%d", &arr[index]);
    }
    qsort(arr, limit, sizeof(int), compare);

    for (int indexA = 0; indexA < limit; indexA++) {
        for (int indexB = indexA + 1; indexB < limit; indexB++) {
            if (arr[indexA] == arr[indexB]) {
                int num = arr[indexA];
                for (int indexRepeat = 0; indexRepeat < repeatCount; indexRepeat++){
                    if (num == repeatNums[indexRepeat]) {
                        goto sortEnd; // continue nested loop
                    }
                }

                printf("%s%d", repeatCount ? " " : "", num);
                repeatNums[repeatCount++] = num;
            }
            sortEnd:;
        }
    }

    if (!repeatCount)  {
        puts("No repeated number!");
    }
    putchar('\n');
}