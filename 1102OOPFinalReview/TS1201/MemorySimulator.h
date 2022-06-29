#include <iostream>
#include <string>
#include <vector>
#include <map>

struct methods
{
	// Get
	void getChar();
	void getShort();
	void getInt();
	void getString();
	// Set
	void setChar();
	void setShort();
	void setInt();
	void setString();
};

typedef void (methods::* MemorySimulatorMethodT)(void);
typedef std::map<std::string, MemorySimulatorMethodT> MemorySimulatorMethodMap;

void parser(std::string, std::string, int);
bool inRange(int, int);

int memSize, commendLimits, nowPosition;
std::string accessDeind = "Violation Access";
std::string nowDir, nowMethod;
std::vector<unsigned char> memory;
std::map<std::string, int> typeSize = {
	{"char", 0},
	{"short", 1},
	{"int", 3},
	{"String", nowDir == "Set" ? nowMethod.size() : 0}
};

bool inRange(int startPoint, int requestLimit)
{
	return startPoint + requestLimit < memSize;
}

void parser(std::string direction, std::string type, int position)
{
	std::map<std::string, MemorySimulatorMethodMap> methods;
	// Get
	methods["Get"]["char"] = &methods::getChar;
	methods["Get"]["short"] = &methods::getShort;
	methods["Get"]["int"] = &methods::getInt;
	methods["Get"]["String"] = &methods::getString;
	// Set
	methods["Set"]["char"] = &methods::setChar;
	methods["Set"]["short"] = &methods::setShort;
	methods["Set"]["int"] = &methods::setInt;
	methods["Set"]["String"] = &methods::setString;
	// update
	nowDir = direction;
	nowMethod = type;
	nowPosition = position;
	// valid
	if (inRange(position, typeSize[type]))
	{
		methods[direction][type];
	}
	else
	{
		std::cout << accessDeind << std::endl;
	}
}

void methods::setChar()
{
	char input;
	std::cin >> input;
}

void methods::setShort()
{
	short input;
	std::cin >> input;
}

void methods::setInt()
{
	char input;
	std::cin >> input;
}

void methods::setString()
{
	std::string input;
	std::cin >> input;
}

void methods::getChar()
{
	std::cout << (int)memory[nowPosition] << std::endl;
}
