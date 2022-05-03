// Name: ¤ý¥¿§»
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: The Translation Machine
#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>
using namespace std;

bool CanTranslate(char word1, char word2, map<char, vector<char>> map, vector<char> used) {
	if (word1 == word2)
	{
		return true;
	}
	if (map.find(word1) == map.end())
	{
		return false;
	}
	for (int i = 0; i < used.size(); i++)
	{
		if (used[i] == word1)
		{
			return false;
		}
	}
	used.push_back(word1);
	for (int i = 0; i < map.at(word1).size(); i++)
	{
		if (CanTranslate(map.at(word1)[i], word2, map, used))
		{
			return true;
		}
	}
	return false;
}

int main() {
	int m;
	int n;
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0)
		{
			break;
		}
		map<char, vector<char>> map;
		for (int i = 0; i < m; i++)
		{
			char a;
			char b;
			cin >> a >> b;
			if (!(a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z'))
			{
				cout << "ERROR" << endl;
				continue;
			}
			if (map.find(a) != map.end())
			{
				map.at(a).push_back(b);
			}
			else
			{
				vector<char> new_vector;
				new_vector.push_back(b);
				map.insert_or_assign(a, new_vector);

			}
		}
		string a;
		string b;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			if (a.size() != b.size())
			{
				cout << "no" << endl;
				continue;
			}
			int can = 1;
			for (int i = 0; i < a.size(); i++)
			{
				if (!(a[i] >= 'a' && a[i] <= 'z' && b[i] >= 'a' && b[i] <= 'z'))
				{
					cout << "ERROR" << endl;
					can = 2;
					break;
				}
				vector<char> used;
				if (!CanTranslate(a[i], b[i], map, used))
				{
					can = 0;
					break;
				}
			}
			if (can == 1)
			{
				cout << "yes" << endl;
			}
			else if (can == 0)
			{
				cout << "no" << endl;
			}
		}
	}
}