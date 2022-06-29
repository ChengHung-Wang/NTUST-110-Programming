/************************************************************************
File:        source.cpp

Author:
		���s�Aea5878158@gmail.com
Modifier:
		�௧�N�Acheeryuchi@gmail.com
		���Y���Awindyhuang6@gmail.com
		���T�t�AJYCReports@gmail.com
Comment:
		�򥻿�J��V���ʥ\��Aw s a d ���ʸ}��W�U���k�A�ťէ��ܸ}�⯸�ߤ��a�O�r���A��T�W�i�H�W�[�g��
		ESC�O���}�e���C�P�ɧ�s�Ϫ��W����T�C

************************************************************************/

#include "main.h"
#include "Hero.h"
#include "Creature.h"
Hero gHero(2, 2);

// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

const int GWIDTH = 10;
const int GHEIGHT = 10;
const double gTimeLog = 0.033;

// Distance
const int gDistance = 4;

// �Ψ��x�s�������
char gBoard[GHEIGHT][GWIDTH] = {
	GWALL, GWALL, GWALL, GWALL, GWALL,
	GWALL, GNOTHING, GNOTHING, GNOTHING, GWALL,
	GWALL, GNOTHING, GNOTHING, GNOTHING, GWALL,
	GWALL, GNOTHING, GNOTHING, GNOTHING, GWALL,
	GWALL, GWALL, GWALL, GWALL, GWALL};

// �w�q���ؿ�J���O�P�����}�Cindex
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	INVALID,
};

// Creature gCreature;
std::vector<Creature*> gCreatures;

// function declare
// ������J���A
void keyUpdate(bool key[]);
// �P�_��m�O�_����
bool isPositionValid(Position &loc);
// ��l�ƪ���
void setupBoard();
// ��X����
void draw(void);
// ��X������T
void drawInfo(void);

// �{���D�X�ʨ禡
void update(bool key[]);

// Trigger gTrigger(5, 5, 10);
// Trigger gTrigger1;
std::vector<Item*> gItems;

int main(int argc, char **argv)
{
	// �ΨӺ޲z��L��J���A���}�C
	bool gKeyState[6];

	// Setup a clear dungeon
	setupBoard();

	gCreatures.push_back(new TA());
	gCreatures.push_back(new Professor());
	gCreatures[0]->setPos(5, 6);
	gCreatures[1]->setPos(6, 6);
	
	gItems.push_back(new Trigger(5, 5, 10));
	gItems.push_back(new Medicine(7, 5, 5));

	// Draw the bord and information
	draw();
	drawInfo();

	// Variable for game loop
	clock_t startT, endT;
	startT = clock();
	endT = clock();

	// Get the press key
	keyUpdate(gKeyState);

	// Run the game loop
	while (!gKeyState[ValidInput::EESC])
	{
		// Compute the time lap
		double timeFrame = (double)(endT - startT) / CLOCKS_PER_SEC;

		// Execute the game loop
		if (timeFrame >= gTimeLog)
		{
			update(gKeyState);
			startT = clock();
		}

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();
	}

	system("pause");
	return 0;
}

//******************************************************************
//
// * ������J���A
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++)
	{
		key[i] = false;
	}
	char input = _getch();
	switch (input)
	{
	case 'w':
		key[ValidInput::EW] = true;
		break;
	case 's':
		key[ValidInput::ES] = true;
		break;
	case 'a':
		key[ValidInput::EA] = true;
		break;
	case 'd':
		key[ValidInput::ED] = true;
		break;
	case ' ':
		key[ValidInput::ESPACE] = true;
		break;
	case 27:
		key[ValidInput::EESC] = true;
		break;
	default:
		break;
	}
}

//******************************************************************
//
// * �P�_��m�O�_����
//==================================================================
bool isPositionValid(Position &pos)
//==================================================================
{
	// Check whether it is an empty space
	if (gBoard[pos.y][pos.x] == GNOTHING)
	{
		return true;
	}
	return false;
}

//******************************************************************
//
// * clip algroithm
//==================================================================
float clip(float n, float minimum, float maximum)
//==================================================================
{
	return std::max(minimum, std::min(n, maximum));
}

//******************************************************************
//
// * �Q�� call-by-referce �N�p��o�쪺��V�^��
//==================================================================
bool canSee(Position cPos, Position hPos, Position &dir)
//==================================================================
{
	// the dir_x and dir_y value are call-by-refernce
	dir.x = (int)clip((float)(hPos.x - cPos.x), -1.f, 1.f); // clip the value between -1 ~ 1
	dir.y = (int)clip((float)(hPos.y - cPos.y), -1.f, 1.f);
	int count = 0;
	do
	{
		// spot the target position
		if (cPos.x + dir.x * count == hPos.x &&
			cPos.y + dir.y * count == hPos.y)
		{
			return true;
		}
		count++;
	} while (count < gDistance); // check the range in 4 units
	return false;
}

//******************************************************************
//
// * Setup the board
//==================================================================
void setupBoard()
//==================================================================
{
	for (int i = 0; i < GHEIGHT; i++)
	{
		for (int j = 0; j < GWIDTH; j++)
		{
			if (i == 0 || i == GHEIGHT - 1)
			{
				gBoard[i][j] = GWALL;
			}
			else if (j == 0 || j == GWIDTH - 1)
			{
				gBoard[i][j] = GWALL;
			}
			else
			{
				gBoard[i][j] = GNOTHING;
			}
		}
	}
}

//******************************************************************
//
// * Draw the board
//==================================================================
void draw()
//==================================================================
{
	// Add the hero into the board
	char drawBoard[GHEIGHT][GWIDTH];

	for (int i = 0; i < GHEIGHT; i++)
	{
		for (int j = 0; j < GWIDTH; j++)
		{
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

	for (const auto &item : gCreatures) 
	{
		Position c = (*item).getPos();
		drawBoard[c.y][c.x] = (*item).getIcon();
	}

	for (const auto& item : gItems)
	{
		Position c = (*item).getPos();
		drawBoard[c.y][c.x] = (*item).getIcon();
	}

	for (const auto& item : gCreatures) {
		Position cPos = (*item).getPos();
		if (h.x == cPos.x && h.y == cPos.y) {
			gHero.damage(1);
		}
	}

	/************************************************************************/

	// Draw the board
	for (int i = 0; i < GHEIGHT; i++)
	{
		for (int j = 0; j < GWIDTH; j++)
		{
			std::cout << drawBoard[i][j]; //  output
		}
		std::cout << "\n";
	}
}

//******************************************************************
//
// * Output information
//==================================================================
void drawInfo(void)
//==================================================================
{
	std::cout << "The hero is level " << gHero.getLevel() << "\n";
	std::cout << "has " << gHero.getExp() << " EXP"
			  << "\n";
	std::cout << "need " << gHero.getMaxExp() - gHero.getExp() << " to level up\n";
	std::cout << "Heo has " << gHero.getHealth() << " health\n";
	std::cout << "Use arrow key to move Hero @\n";
	std::cout << "Press ESC key to exit\n";
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
	// �M������
	system("CLS");

	// �O�_��input
	bool hasInput = false;
	if (key[ValidInput::EW])
	{
		gHero.move(0, -1);
		hasInput = true;
	}
	else if (key[ValidInput::ES])
	{
		gHero.move(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::EA])
	{
		gHero.move(-1, 0);
		hasInput = true;
	}
	else if (key[ValidInput::ED])
	{
		gHero.move(1, 0);
		hasInput = true;
	}
	else
	{
		std::cout << "invalid input\n";
	}
	for (const auto& item : gCreatures)
	{
		(*item).update(gHero.getPos());
	}
	
	for (const auto& item : gItems)
	{
		(*item).update(gHero);
	}

	draw();
	drawInfo();
}
