#include <stdio.h>
#pragma warning(disable : 4996)
int main()
{
    float num[2], sum;
    char method;
    // + - * /
    scanf("%f %c %f", &num[0], &method, &num[1]);
    switch (method)
    {
        case '+':
            sum = num[0] + num[1];
            break;
        case '-':
            sum = num[0] - num[1];
            break;
        case '*':
            sum = num[0] * num[1];
            break;
        case '/':
            if ((int)num[1] == 0) {
                printf("Division by zero");
                return 0;
            }
            sum = num[0] / num[1];
            break;
    }
    printf("%.2f %c %.2f = %.2f", num[0], method, num[1], sum);
    return 0;
}