#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

char ans[100][2];
int find, limit, now = 0, diskNumber[100];
int test(int diskCount, char a, char b, char c);

int main()
{
    scanf("%d\n%d", &limit, &find);
    if (limit < 1) {
        printf("Invalid disk number\n");
        return 0;
    }

    test(limit, 'A', 'B', 'C');

    if (find > now) {
        printf("Step out of range\n");
        return 0;
    }
    printf("Disk %d moved from %c to %c\n", diskNumber[find - 1], ans[find - 1][0], ans[find - 1][1]);
    return 0;
}

int test(int diskCount, char a, char b, char c) {
    if (diskCount == 1) {
        ans[now][0] = a;
        ans[now][1] = c;
        diskNumber[now] = diskCount;
        now++;
    }
    else {
        test(diskCount - 1, a, c, b);
        ans[now][0] = a;
        ans[now][1] = c;
        diskNumber[now] = diskCount;
        now++;
        test(diskCount - 1, b, a, c);
    }
    return 0;
}