#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"

//************************************************************
// Item Class
//************************************************************
class Item
{
protected:
	Position sPos;	  // Hero location
	char sIcon = 'I'; // Hero icon

public:
	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y)
	{
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// update
	virtual void update(Hero& h) { }
};


//************************************************************
// Bug Class(role 2)
//************************************************************
class Medicine : public Item
{
private: 
	int power; // how many restore for blood.
public:
	// Default constructor
	Medicine(void)
	{
		this->sPos.x = 6;
		this->sPos.y = 7;
		this->power = 5;
		this->sIcon = 'M';
	};

	// Setting constructor
	Medicine(int x, int y, int amt, char icon = 'M')
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->power = amt;
		this->sIcon = icon;
	};

	// Setting constructor
	Medicine(Position& pos, int amt, char icon = 'M')
	{
		this->sPos = pos;
		this->power = amt;
		this->sIcon = icon;
	};

	void update(Hero& h)
	{
		if (this->sPos.x == h.getPos().x && this->sPos.y == h.getPos().y)
		{
			h.damage(-this->power); // heal hero
		}
	}
};

//************************************************************
// Trigger Class
//************************************************************
class Trigger : public Item
{
private:
	int sExpAmount; // Set up the amount gain
public:
	// Default constructor
	Trigger(void)
	{
		this->sPos.x = 6;
		this->sPos.y = 7;
		this->sExpAmount = 5;
		this->sIcon = 'T';
	};

	// Setting constructor
	Trigger(int x, int y, int amt, char icon = 'T')
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sExpAmount = amt;
		this->sIcon = icon;
	};

	// Setting constructor
	Trigger(Position &pos, int amt, char icon = 'T')
	{
		this->sPos = pos;
		this->sExpAmount = amt;
		this->sIcon = icon;
	};

	// Set the amount
	void SetAmount(int amt) { this->sExpAmount = amt; }

	// Get the amount
	int getExpAmount(void) { return this->sExpAmount; }

	void trigger(Hero &h)
	{
		h.gainEXP(sExpAmount);
	}

	void update(Hero &h)
	{
		if (this->sPos.x == h.getPos().x && this->sPos.y == h.getPos().y)
		{
			this->trigger(h);
		}
	}
};
