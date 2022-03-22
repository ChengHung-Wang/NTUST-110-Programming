#include <stdio.h>

int main()
{
    int a, b;
    char method[2];
    scanf_s("%d", &a);
    scanf_s("%s", &method, 2);
    scanf_s("%d", &b);

    printf("%d %s %d", a, &method, b);
    return 0;
}