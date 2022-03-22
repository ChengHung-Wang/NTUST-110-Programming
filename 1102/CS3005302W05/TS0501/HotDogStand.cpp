#include "HotDogStand.h"
#include <iostream>
using namespace std;

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand()
{
	hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const string id)
{
	standId = id;
	hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const string id, int amount)
{
	standId = id;
	hotDogSellAmount = amount;
	totalSellAmount += amount;
}


HotDogStand::~HotDogStand()
{

}

void HotDogStand::justSold()
{
	hotDogSellAmount++;
	totalSellAmount++;
}

void HotDogStand::print()
{
	std::cout << standId << " " << hotDogSellAmount << endl;
}

int HotDogStand::thisStandSoldAmount()
{
	return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
