#pragma once
#include <string>
using namespace std;
class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(const string id);
	HotDogStand(const string id, int amount);
	~HotDogStand();
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount();
private:
	string standId;
	int hotDogSellAmount;
	static int totalSellAmount;
};

