#pragma once
//************************************************************
// The location in the board
//************************************************************

// Transfer Position change to overloading functions here
/*Please implement your code here*/
struct Position {
	int x; // X, y Coordinate
	int y;

	Position& operator+(int distance) {
		this->y -= distance;
		return *this;
	}

	Position& operator-(int distance) {
		this->y += distance;
		return *this;
	}

	Position& operator*(int distance) {
		this->x -= distance;
		return *this;
	}

	Position& operator/(int distance) {
		this->x += distance;
		return *this;
	}
};

/************************************************************************/
