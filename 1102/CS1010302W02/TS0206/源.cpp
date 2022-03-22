// Name: ¤ý¥¿§»
// Date: February 24, 2022
// Last Update: February 24, 2022
// Problem statement: Compute The Tax
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

float calc(float money) {
    float pay;
    if (money < 750) {
        pay = money / 100;
    }
    else if (money >= 750 && money < 2250) {
        pay = 7.50 + ((money - 750) / 100 * 2);
    }
    else if (money >= 2250 && money < 3750) {
        pay = 37.50 + ((money - 2250) / 100 * 3);
    }
    else if (money >= 3750 && money < 5250) {
        pay = 82.50 + ((money - 3750) / 100 * 4);
    }
    else if (money >= 5250 && money < 7000) {
        pay = 142.50 + ((money - 5250) / 100 * 5);
    }
    else if (money >= 7000) {
        pay = 230.00 + ((money - 7000) / 100 * 6);
    }
    return pay;
}

int main() {
    float input;
    while (std::cin >> input) {
        printf("%.2f\n", calc(input));
    }
}