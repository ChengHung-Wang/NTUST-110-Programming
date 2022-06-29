#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int memSize, runLimit, accessPosition;
string method, targetType, inputContent, accessDeindMSG = "Violation Access";
vector<unsigned char> memory;
bool inRange(int containerSize, int position, int requestLimit)
{
	return position + requestLimit < containerSize;
}
struct methods
{
	void getChar();
	void getShort();
	void getInt();
	void getString();
	void setChar();
	void setShort();
	void setInt();
	void setString();
};
map<string, int> typeOffsetSize = {
	{"char", 0},
	{"short", 1},
	{"int", 3},
	{"String", 0}
};

vector<string> splitBySpace(string input)
{
	vector<string> result;
	string stack = "";
	char target = ' ';
	for (const char& item : input)
	{
		if (item == target)
		{
			result.push_back(stack);
			stack = "";
		}else if (item != '\n')
		{
			stack += item;
		}
	}
	if (stack != "")
	{
		result.push_back(stack);
	}
	return result;
}

int main()
{
	cin >> memSize >> runLimit;
	memory.resize(memSize, 0);
	cin.get();
	for (int step = 0; step < runLimit; step ++)
	{
		string thisLine;
		getline(cin, thisLine);
		vector<string> config = splitBySpace(thisLine);
		method = config[0];
		accessPosition = stoi(config[1]);
		targetType = config[2];
		// update String content
		if (method == "Set")
		{
			inputContent = config[3];
			if (targetType == "String" && method == "Set" && config.size() > 4)
			{
				for (int index = 4; index < config.size(); index++)
				{
					inputContent += (' ' + config[index]);
				}
			}
			else
			{
				inputContent = config[3];
			}
		}
		// valid check
		if (! inRange(memSize, accessPosition, method ==  "Set" ? inputContent.size() : typeOffsetSize[targetType]))
		{
			cout << accessDeindMSG << endl;
			if (method == "Get")
			{
				continue;
			}
		}
		// method switch
		if (method == "Set")
		{
			if (targetType == "char")
			{
				memory[accessPosition] = stoi(inputContent);
			}else if (targetType == "short")
			{
				unsigned char data = stoi(inputContent);
				for (int index = accessPosition; data; data >>= 8, index ++)
				{
					if (index < memSize)
					{
						memory[index] = (char)(data & 0xff);
					}
				}
			}else if (targetType == "int")
			{
				unsigned int data = stoi(inputContent);
				for (int index = accessPosition; data; data >>= 8, index++)
				{
					if (index < memSize)
					{
						memory[index] = (char)(data & 0xff);
					}
				}
			}else if (targetType == "String")
			{
				for (int index = 0; index < inputContent.size(); index ++)
				{
					if (index + accessPosition < memSize)
					{
						memory[index + accessPosition] = inputContent[index];
					}
				}
			}
		} else if (method == "Get")
		{
			if (targetType == "int")
			{
				unsigned int data(0);
				for (int index = accessPosition, base = 1; index < typeOffsetSize[targetType] + 1; index ++, base <<= 8)
				{
					data += (unsigned int)memory[accessPosition + index] * base;
				}
				cout << data << endl;
			}else if (targetType == "short")
			{
				unsigned int data(0);
				for (int index = accessPosition, base = 1; index < typeOffsetSize[targetType] + 1; index++, base <<= 8)
				{
					data += (unsigned int)memory[accessPosition + index] * base;
				}
				cout << data << endl;
			}else if (targetType == "char")
			{
				cout << (int)memory[accessPosition] << endl;
			}else if (targetType == "String")
			{
				for (int index = accessPosition; index < memory.size(); index ++)
				{
					cout << memory[index];
				}
				cout << endl;
			}
		}
	}
}