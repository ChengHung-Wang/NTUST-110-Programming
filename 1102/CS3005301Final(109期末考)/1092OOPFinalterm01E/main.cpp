#include <string>
#include <list>
#include <map>
#include <iostream>
using namespace std;

//class Floor {
//	int floor;
//	int minutes;
//	Floor(int floor, int minutes) {
//		this->floor = floor;
//		this->minutes = minutes;
//	}
//};

int main() {
	int now = 1;
	int time = 1;
	int n;
	int count = 0;
	cin >> n;
	int floor;
	int minutes;
	list<int> floors;
	list<int> minuteses;
	for(int i = 0; i < n; i++)
	{
		cin >> minutes >> floor;
		floors.push_back(floor);
		minuteses.push_back(minutes);
	}
	list<int> destinations;
	list<int> output1;
	list<int> output2;
	bool isUp = true;
	int destination = -1;
	while (true)
	{
		output1.push_back(time);
		output2.push_back(now);
		list<int>::iterator inter_des = destinations.begin();
		while (inter_des != destinations.end())
		{
			if (*inter_des == now)
			{
				destinations.erase(inter_des);
				inter_des = destinations.begin();
			}
			else 
			{
				inter_des++;
			}
		}
		if (destination == now)
		{
			if (destinations.size() == 0)
			{
				destination = -1;
			}
			else 
			{
				if (isUp)
				{
					int max = -1;
					for (list<int>::iterator inter_des2 = destinations.begin(); inter_des2 != destinations.end(); inter_des2++)
					{
						max = *inter_des2 > max ? *inter_des2 : max;
					}
					if (max < now)
					{
						isUp = false;
					}
					destination = max;
				}
				else 
				{
					int min = -1;
					for (list<int>::iterator inter_des2 = destinations.begin(); inter_des2 != destinations.end(); inter_des2++)
					{
						min = *inter_des2 > min ? *inter_des2 : min;
					}
					if (min > now)
					{
						isUp = true;
					}
					destination = min;
				}
				list<int>::iterator inter_des = destinations.begin();
				while (inter_des != destinations.end())
				{
					if (*inter_des == now)
					{
						destinations.erase(inter_des);
						inter_des = destinations.begin();
					}
					else
					{
						inter_des++;
					}
				}
			}
		}
		list<int>::iterator inter2 = floors.begin();
		for (list<int>::iterator inter = minuteses.begin() ; inter != minuteses.end(); inter++)
		{
			if (*inter == time)
			{
				count++;
				bool isHaving = false;
				for (list<int>::iterator inter_des2 = destinations.begin(); inter_des2 != destinations.end(); inter_des2++)
				{
					if (*inter_des2 == *inter2)
					{
						isHaving = true;
						break;
					}
				}
				if (!isHaving)
				{
					if (*inter2 != now)
					{
						destinations.push_back(*inter2);
						if (destination == -1)
						{
							destination = *inter2;
							isUp = destination >= now;
							list<int>::iterator inter_des = destinations.begin();
							while (inter_des != destinations.end())
							{
								if (*inter_des == now)
								{
									destinations.erase(inter_des);
									inter_des = destinations.begin();
								}
								else
								{
									inter_des++;
								}
							}
						}
					}
				}
			}
			inter2++;
		}
		if (destinations.size() == 0 && count == n)
		{
			break;
		}
		if (destination != -1)
		{
			now += (isUp ? 1 : -1);
		}
		time++;
	}
	int total = output1.size();
	for (int i = 0; i < total;i ++)
	{
		cout << output1.front() << " " << output2.front() << endl;
		output1.pop_front();
		output2.pop_front();
	}
}