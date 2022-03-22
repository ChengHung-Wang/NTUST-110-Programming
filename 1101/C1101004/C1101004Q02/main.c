#include <stdio.h>

int main()
{
    float first, second;
    scanf_s("%f\n%f", &first, &second);
    printf("%.2f + %.2f = %.2f\n", first, second, first + second);
    printf("%.2f - %.2f = %.2f\n", first, second, first - second);
    printf("%.2f * %.2f = %.2f\n", first, second, first * second);
    printf("%.2f / %.2f = %.2f", first, second, first / second);
    return 0;
}