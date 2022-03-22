// Name: ¤ý¥¿§»
// Date: March 13, 2022
// Last Update: March 13, 2022
// Problem statement: Collatz Conjecture
#include <iostream>
using namespace std;
int calc(int, int);
int process(int);

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << a << " " << b << " " << calc(a, b) << endl;
    }
    return 0;
}

int calc(int a, int b) {
    int count = 0;
    int tempA, tempB;
    tempA = a, tempB = b;
    if (tempA > tempB) {
        tempA = b;
        tempB = a;
    }
    if (tempB <= 1) {
        return 1;
    }
    for (int index = tempA; index <= tempB; index++) {
        int limit = process(index);
        if (limit > count) {
            count = limit;
        }
    }
    return count + 1;
}

int process(int num) {
    int total = 0;
    int nowNumber = num;
    while (nowNumber != 1) {
        if (nowNumber % 2) {
            nowNumber = (nowNumber * 3) + 1;
        }
        else {
            nowNumber = nowNumber / 2;
        }
        total++;
    }
    return total;
}