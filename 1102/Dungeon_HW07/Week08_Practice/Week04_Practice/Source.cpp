/************************************************************************
File:        source.cpp

Author:
		鍾賢廣，ea5878158@gmail.com
Modifier:
		賴祐吉，cheeryuchi@gmail.com
		黃欣云，windyhuang6@gmail.com
		陳俊宇，JYCReports@gmail.com
Comment:
		基本輸入方向移動功能，w s a d 移動腳色上下左右，空白改變腳色站立之地板字元，到T上可以增加經驗
		ESC是離開畫面。同時更新圖版上的資訊。

************************************************************************/

#include "main.h"
#include "Hero.h"

Hero gHero;

class Creature {//creature class 
private:
	Position	sPos;			// Creature position
	char sIcon = 'C';			// Creature icon
	int sAttack;				// Creature attack
public:
	// Default constructor
	Creature(void) {
		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = 'C';
	};

	Creature(int x, int y, int atk, char icon) {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sAttack = atk;
		this->sIcon = icon;
	}

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Set attack
	void setAttack(int atk) { this->sAttack = atk; }

	// Get attack
	int getAttack(void) { return this->sAttack; }

public:
	void update(Position hPos) {
		Position dir;
		if (canSee(this->sPos, hPos, dir)) {
			std::cout << "Creature has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
			this->sIcon = '!';
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
		else {
			std::cout << "Creature didn't find the Hero\n";
			this->sIcon = 'C';
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

// Constent value

// const int GWIDTH = 20;
// const int GHEIGHT = 15;
const double gTimeLog = 0.033;

// Distance
const int gDistance = 4;

// mapFiles
vector<string> runningConfigs = {
	"./map1.txt",
	"./map2.txt",
};

// 用來儲存版面資料
int gWidth;
int gHeight;
char gWall;
char gNothing;
vector<vector<char>> gBoard;
// char gBoard[GHEIGHT][GWIDTH] = {
// 	GWALL,		GWALL,		GWALL,		GWALL,		GWALL,
// 	GWALL,		GNOTHING,	GNOTHING,	GNOTHING,	GWALL,
// 	GWALL,		GNOTHING,	GNOTHING,	GNOTHING,	GWALL,
// 	GWALL,		GNOTHING,	GNOTHING,	GNOTHING,	GWALL,
// 	GWALL,		GWALL,		GWALL,		GWALL,		GWALL
// };

// 定義六種輸入指令與對應陣列index
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

Creature gCreature;

// function declare
// 偵測輸入狀態
void keyUpdate(bool key[]);
// 判斷位置是否為空
bool isPositionValid(Position& loc);
// 初始化版面
void setupBoard();
// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);

// 程式主驅動函式
void update(bool key[]);

// get running-config
void getRunningConfig(string);

// set running-config
void setRunningConfig(string);

Trigger  gTrigger(5, 5, 10);
Trigger  gTrigger1;

int main(int argc, char** argv)
{
	// TODO: select a running-config index
	for (int i = 1; i < runningConfigs.size() + 1; i++)
	{
		cout << i << " => " << runningConfigs[i - 1] << endl;
	}
	cout << "enter running-config key: ";
	// cout << "输入running-config的键值: ";
	int fileIndex;
	cin >> fileIndex;
	system("CLS");

	// TODO: setRunningConfig
	getRunningConfig(runningConfigs[fileIndex - 1]);

	// 用來管理鍵盤輸入狀態的陣列
	bool gKeyState[6];

	// Setup a clear dungeon
	setupBoard();

	// gCreature.setPos(5, 6);

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
	while (!gKeyState[ValidInput::EESC]) {
		// Compute the time lap
		double timeFrame = (double)(endT - startT) / CLOCKS_PER_SEC;

		// Execute the game loop
		if (timeFrame >= gTimeLog) {
			update(gKeyState);
			startT = clock();
		}

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();
	}

	// TODO: save file
	setRunningConfig(runningConfigs[fileIndex - 1]);
	system("pause");
	return 0;
}

//******************************************************************
//
// * 偵測輸入狀態
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++) {
		key[i] = false;
	}
	char input = _getch();
	switch (input) {
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
// * 判斷位置是否為空
//==================================================================
bool isPositionValid(Position& pos)
//==================================================================
{
	// Check whether it is an empty space
	if (gBoard[pos.y][pos.x] == gNothing) {
		return true;
	}
	return false;
}

//******************************************************************
//
// * clip algroithm
//==================================================================
float clip(float n, float minimun, float maximum)
//==================================================================
{
	return std::max(minimun, std::min(n, maximum));
}

//******************************************************************
//
// * 利用 call-by-referce 將計算得到的方向回傳
//==================================================================
bool canSee(Position cPos, Position hPos, Position& dir)
//==================================================================
{
	// the dir_x and dir_y value are call-by-refernce
	dir.x = (int)clip((float)(hPos.x - cPos.x), -1.f, 1.f); // clip the value between -1 ~ 1
	dir.y = (int)clip((float)(hPos.y - cPos.y), -1.f, 1.f);
	int count = 0;
	do {
		// spot the target position
		if (cPos.x + dir.x * count == hPos.x &&
			cPos.y + dir.y * count == hPos.y) {
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
	for (int i = 0; i < gHeight; i++) {
		for (int j = 0; j < gWidth; j++) {
			if (i == 0 || i == gHeight - 1) {
				gBoard[i][j] = gWall;
			}
			else if (j == 0 || j == gWidth - 1) {
				gBoard[i][j] = gWall;
			}
			else {
				gBoard[i][j] = gNothing;
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
	vector<vector<char>> drawBoard(gHeight);

	for (int i = 0; i < gHeight; i++) {
		drawBoard[i].resize(gWidth);
		for (int j = 0; j < gWidth; j++) {
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

	Position c = gCreature.getPos();
	drawBoard[c.y][c.x] = gCreature.getIcon();

	Position t = gTrigger.getPos();
	drawBoard[t.y][t.x] = gTrigger.getIcon();

	Position t1 = gTrigger1.getPos();
	drawBoard[t1.y][t1.x] = gTrigger1.getIcon();

	// Hero loses health when steps on creature
	/*Please implement your code here*/

	if (h.x == c.x && h.y == c.y)
	{
		gHero.damage(gCreature.getAttack());
	}

	/************************************************************************/

	// Draw the board
	for (int i = 0; i < gHeight; i++) {
		for (int j = 0; j < gWidth; j++) {
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
	std::cout << "has " << gHero.getExp() << " EXP" << "\n";
	std::cout << "need " << gHero.getMaxExp() - gHero.getExp() << " to level up\n";
	std::cout << "Heo has " << gHero.getHealth() << " health\n";
	std::cout << "Use arrow key to moved Hero @\n";
	std::cout << "Use Every time you step on a trigger T. the hero gets " << gTrigger.getExpAmount() << " or " << gTrigger1.getExpAmount() << " EXP points\n";
	std::cout << "Press ESC key to exit\n";
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
	// 清除版面
	system("CLS");

	// 是否有input
	bool hasInput = false;
	if (key[ValidInput::EW]) {
		gHero.move(0, -1);
		hasInput = true;
	}
	else if (key[ValidInput::ES]) {
		gHero.move(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::EA]) {
		gHero.move(-1, 0);
		hasInput = true;
	}
	else if (key[ValidInput::ED]) {
		gHero.move(1, 0);
		hasInput = true;
	}
	else {
		std::cout << "invalid input\n";
	}
	gCreature.update(gHero.getPos());
	gTrigger.update(gHero);
	gTrigger1.update(gHero);
	draw();
	drawInfo();
}

// get running-config
void getRunningConfig(string fileStr) {
	/*
		-----------------------
		running-config format:
		-----------------------
		width height
		wall
		Nothing
		Trigger Trigger2 Hero Creature
		TriggerY TriggerX Trigger2Y Trigger2X
		TriggerExpAmount Trigger2ExpAmount
		HeroY HeroX
		HeroExp HeroMaxExp HeroLevel HeroHealth
		CreatureY CreatureX
		CreatureAttack
	*/
	fstream fs;
	fs.open(fileStr, ios::in);

	// parser running-config
	char gTriggerIcon, gTrigger1Icon, gHeroIcon, gCreatureIcon;
	int gTriggerY, gTriggerX, gTriggerExpAmount, gTrigger1Y, gTrigger1X, gTrigger1ExpAmount;
	int gHeroY, gHeroX, gHeroExp, gHeroMaxExp, gHeroLevel, gHostHealth;
	int gCreatureY, gCreatureX, gCreatureAttack;

	// set canvas width and height
	fs >> gWidth >> gHeight;
	fs.ignore();
	// get member symbol
	fs.get(gWall);
	fs.ignore();
	fs.get(gNothing);
	fs.ignore();
	fs >> gTriggerIcon >> gTrigger1Icon >> gHeroIcon >> gCreatureIcon;
	fs.ignore();
	// get Trigger target info
	fs >> gTriggerY >> gTriggerX >> gTrigger1Y >> gTrigger1X;
	fs.ignore();
	fs >> gTriggerExpAmount >> gTrigger1ExpAmount;
	fs.ignore();
	// get Hero target info
	fs >> gHeroY >> gHeroX;
	fs.ignore();
	fs >> gHeroExp >> gHeroMaxExp >> gHeroLevel >> gHostHealth;
	fs.ignore();
	// get Creature target info
	fs >> gCreatureY >> gCreatureX;
	fs.ignore();
	fs >> gCreatureAttack;
	fs.ignore();

	// set members
	gTrigger = Trigger(gTriggerX, gTriggerY, gTriggerExpAmount, gTriggerIcon);
	gTrigger1 = Trigger(gTrigger1X, gTrigger1Y, gTrigger1ExpAmount, gTrigger1Icon);

	gHero = Hero(gHeroX, gHeroY, gHeroLevel, gHeroMaxExp, gHeroExp, gHostHealth, gHeroIcon);

	gCreature = Creature(gCreatureX, gCreatureY, gCreatureAttack, gCreatureIcon);

	gBoard.resize(gHeight);
	for (auto& row : gBoard)
	{
		row.resize(gWidth);
	}
	fs.close();
}

// set running-config
void setRunningConfig(string fileStr) {
	/*
		-----------------------
		running-config format:
		-----------------------
		width height
		wall
		Nothing
		Trigger Trigger2 Hero Creature
		TriggerY TriggerX Trigger2Y Trigger2X
		TriggerExpAmount Trigger2ExpAmount
		HeroY HeroX
		HeroExp HeroMaxExp HeroLevel HeroHealth
		CreatureY CreatureX
		CreatureAttack
	*/
	fstream fsSave;
	fsSave.open(fileStr, ios::out | ios::trunc);

	// save canvas width and height
	fsSave << gWidth << " " << gHeight << endl;

	// save all member's feature
	fsSave << gWall << endl;
	fsSave << gNothing << endl;
	fsSave <<
		gTrigger.getIcon() << " " <<
		gTrigger1.getIcon() << " " <<
		gHero.getIcon() << " " <<
		gCreature.getIcon() <<
		endl;

	// save Trigger's running-config
	fsSave <<
		gTrigger.getPos().y << " " <<
		gTrigger.getPos().x << " " <<
		gTrigger1.getPos().y << " " <<
		gTrigger1.getPos().x << " " <<
		endl;
	fsSave <<
		gTrigger.getExpAmount() << " " <<
		gTrigger1.getExpAmount() <<
		endl;

	// save Hero's running-config
	fsSave << gHero.getPos().y << " " << gHero.getPos().x << endl;
	fsSave <<
		gHero.getExp() << " " <<
		gHero.getMaxExp() << " " <<
		gHero.getLevel() << " " <<
		gHero.getHealth() <<
		endl;

	// save Creature's running-config
	fsSave << gCreature.getPos().y << " " << gCreature.getPos().x << endl;
	fsSave << gCreature.getAttack() << endl;

	fsSave.close();
}