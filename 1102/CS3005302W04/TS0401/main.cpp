// Name: ??????
// Date: March 13, 2022
// Last Update: March 13, 2022
// Problem statement: Class Point in plane
#include <iostream>
#include "Point.h"
using namespace std;

int main(void) {
	Point point;

	point.Set(0, 5);
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;

	point.Move(1, 2);
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;
	for (int i = 0; i < 4; i++) {
		point.Rotate();
		cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;
	}

	return 0;
}