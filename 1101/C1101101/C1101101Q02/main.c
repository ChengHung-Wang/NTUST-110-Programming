#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
struct str
{
    int value;
    int index;
};
int compare(const void* a, const void* b)
{
    // struct str* a1 = (struct str*)a;
    // struct str* a2 = (struct str*)b;
    return (struct str*)a - (struct str*)b;
}
int main()
{
    // 1 -1 -3 0 2 -5 3
    int limit;
    struct str objects[100];
    scanf("%d", &limit);
    for (int index = 0; index < limit; index++) {
        scanf("%d", &objects[index].value);
        objects[index].index = index;
    }
    qsort(objects, limit, sizeof(objects[0]), compare);
    for (int i = 0; i < limit; i++) {
        printf("%d%s", objects[i].index , i == limit - 1 ? "\n" : " ");
    }
}