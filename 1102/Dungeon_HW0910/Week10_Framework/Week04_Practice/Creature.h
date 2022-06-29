#pragma once
#include <string>
#include "Position.h"
#include "main.h"
class Creature
{ // creature class
protected:
	Position sPos;	  // Creature position
	char sIcon = 'C'; // Creature icon
	char show = 'C'; // trust show icon
public:
	// Default constructor
	Creature(void)
	{
		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = 'C';
		this->show = 'C';
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y)
	{
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->show; }

public:
	virtual void update(Position hPos) {  }
};

class TA : public Creature
{
public:
	// init
	TA() :Creature() {
		this->sIcon = 'A';
		this->show = 'A';
	}
	
	void update(Position hPos)
	{
		Position dir;
		if (canSee(this->sPos, hPos, dir))
		{
			std::cout << "TA has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction.\nAre you using PHP?\n";
			this->show = '!';
			int randNum = rand() % 4;
			if (randNum == 0)
			{
				Position test = sPos;
				test.x += dir.x;
				test.y += dir.y;
				if (isPositionValid(test))
				{
					this->sPos.x += dir.x;
					this->sPos.y += dir.y;
				}
			}
		}
		else
		{
			std::cout << "TA didn't find the Hero.\n";
			this->show = this->sIcon;
			int randNum = rand() % 4;
			if (randNum == 0)
			{
				Position test = sPos;
				test.x += 1;
				if (isPositionValid(test))
				{
					this->sPos.x += 1;
				}
				else
				{
					this->sPos.x -= 1;
				}
			}
			if (randNum == 1)
			{
				Position test = sPos;
				test.x -= 1;
				if (isPositionValid(test))
				{
					this->sPos.x -= 1;
				}
				else
				{
					this->sPos.x += 1;
				}
			}
			if (randNum == 2)
			{
				Position test = sPos;
				test.y += 1;
				if (isPositionValid(test))
				{
					this->sPos.y += 1;
				}
				else
				{
					this->sPos.y -= 1;
				}
			}
			if (randNum == 3)
			{
				Position test = sPos;
				test.y -= 1;
				if (isPositionValid(test))
				{
					this->sPos.y -= 1;
				}
				else
				{
					this->sPos.y += 1;
				}
			}
		}
	}
};

class Professor : public Creature
{
public:
	// init 
	Professor() :Creature() {
		this->sIcon = 'P';
		this->show = 'P';
	}
	void update(Position hPos)
	{
		Position dir;
		canSee(this->sPos, hPos, dir);
		std::cout << "Professor always knows your code language, even if you're there ( " << dir.x << ", " << dir.y << " ) direction.\n";
		int randNum = rand() % 4;
		if (randNum == 0)
		{
			Position test = sPos;
			test.x += dir.x;
			test.y += dir.y;
			if (isPositionValid(test))
			{
				this->sPos.x += dir.x;
				this->sPos.y += dir.y;
			}
		}
	}
};