#include <stdio.h>
#pragma warning(disable : 4996)
int main()
{
  int n;
  scanf("%d", &n);

  for (int line = 0; line < n; line++)
  {
    // whitespace
    for (int i = 0; i < n - 1 - line; i++)
    {
      putchar(' ');
    }

    // character
    for (int i = 0; i < line * 2 + 1; i++)
    {
      putchar(line + 'A');
    }

    putchar('\n');
  }
}