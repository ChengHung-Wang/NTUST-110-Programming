// Name: 王正宏
// Date: March 10, 2022
// Last Update: March 10, 2022
// Problem statement: Simple Drawing Program
#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;
int mapX, mapY;
char map[100000][10000];
void L(int x1, int y1, int x2, int y2);
void S(int w, int x, int y);
void T(int w, int x, int y, string order);

void printMap() {
	for (int i = 0; i < mapY; ++i) {
		for (int j = 0; j < mapX; ++j) {
			cout << map[j][i];
		}
		cout << endl;
	}
}
void S(int w, int x, int y) {

	if ((x + w) > mapX || (y + w) > mapY) {
		cout << "Out of range." << endl;
		return;
	}
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < w; ++j) {
			map[x + i][y + j] = 'X';
		}
	}
	printMap();
}
void T(int w, int x, int y, string order) {
	int n;
	w -= 1;
	if (order == "LU") {
		if ((x - w) < 0 || (y - w) < 0) {
			cout << "Out of range." << endl;
			return;
		}
		for (int j = 0; j <= w; ++j) {
			for (int i = 0; i <= w - j; ++i) {
				map[x - j][y - i] = 'X';
			}
		}
	}
	else if (order == "RU") {
		if ((x + w) > mapX || (y - w) < 0) {
			cout << "Out of range." << endl;
			return;
		}
		for (int j = 0; j <= w; ++j) {
			for (int i = 0; i <= w - j; ++i) {
				map[x + j][y - i] = 'X';
			}
		}
	}
	else if (order == "LD") {
		if ((x - w) < 0 || (y + w) > mapY) {
			cout << "Out of range." << endl;
			return;
		}
		for (int j = 0; j <= w; ++j) {
			for (int i = 0; i <= w - j; ++i) {
				map[x - j][y + i] = 'X';
			}
		}
	}
	else if (order == "RD") {
		if ((x + w) > mapX || (y + w) > mapY) {
			cout << "Out of range." << endl;
			return;
		}
		for (int j = 0; j <= w; ++j) {
			for (int i = 0; i <= w - j; ++i) {
				map[x + j][y + i] = 'X';
			}
		}
	}
	printMap();
}
void L(int x1, int y1, int x2, int y2) {
	// from a to b
	int  signX = 1, signY = 1;
	if (x1 >= mapX || x1 < 0 || x2 >= mapX || x2 < 0 || y1 >= mapY || y1 < 0 || y2 >= mapY || y2 < 0) {
		cout << "Out of range." << endl;
		return;
	}
	if (x1 > x2)
		signX = -1;
	else if (x1 == x2)
		signX = 0;
	if (y1 > y2)
		signY = -1;
	else if (y1 == y2)
		signY = 0;
	while (!(x1 == x2 && y1 == y2)) {
		map[x1][y1] = 'X';
		x1 += signX;
		y1 += signY;
	}
	map[x1][y1] = 'X';
	printMap();
}
int main() {
	char s; string order;
	cin >> mapX >> mapY;
	for (int i = 0; i < mapX; ++i) {
		for (int j = 0; j < mapY; ++j) {
			map[i][j] = '*';
		}
	}
	while (cin >> s) {
		int w, x, y;
		string order;
		switch (s) {
		case 'S':
			cin >> w >> x >> y;
			S(w, x, y);
			break;
		case 'T':
			cin >> w >> x >> y >> order;
			T(w, x, y, order);
			break;
		case'L':
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			L(x1, y1, x2, y2);
			break;
		default:
			return 0;
		}
		cout << endl;
	}
}