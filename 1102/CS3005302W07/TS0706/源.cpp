// Name: ¤ý¥¿§»
// Date: April 05, 2022
// Last Update: March 13, 2022
// Problem statement: Shisensho
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Point
{
public:
	int x;
	int y;
	enum class direction :int { UP, DOWN, RIGHT, LEFT };

	Point() {
		this->x = 0;
		this->y = 0;
	}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	bool inRange(int size) const
	{
		if (x < 0 || x >= size)
			return false;
		if (y < 0 || y >= size)
			return false;
		return true;
	}

	static Point mapDirection(direction dir)
	{
		switch (dir)
		{
		case direction::UP:
			return Point(0, -1);
		case direction::DOWN:
			return Point(0, 1);
		case direction::RIGHT:
			return Point(1, 0);
		case direction::LEFT:
			return Point(-1, 0);
		}
	}

	Point operator=(const Point& point)
	{
		return Point(point.x, point.y);
	}

	friend std::istream& operator>>(std::istream& is, Point& point)
	{
		is >> point.x >> point.y;
		point.x++;
		point.y++;
		return is;
	}

	friend bool operator==(const Point& p1, const Point& p2)
	{
		if (p1.x == p2.x && p1.y == p2.y)
			return true;
		return false;
	}

	friend Point operator+(const Point& p1, const Point& p2)
	{
		return Point(p1.x + p2.x, p1.y + p2.y);
	}
};

void resetGraph(vector<vector<int>>& graph)
{
	for (auto& v : graph)
	{
		for (auto& i : v)
		{
			if (i == -1)
				i = 0;
		}
	}
}

bool dfs(vector<vector<int>>& graph, Point now, const Point& end, Point::direction nowFace, int turnTimes)
{
	vector<Point::direction> dirs = {
		Point::direction::UP,
		Point::direction::DOWN,
		Point::direction::RIGHT,
		Point::direction::LEFT
	};
	for (const Point::direction& d : dirs)
	{
		Point temp = now + Point::mapDirection(d);
		
		int turnTemp = (int)(d != nowFace) + turnTimes;

		if (temp == end)
		{
			resetGraph(graph);
			if (turnTemp <= 2)
				return true;
			else
				return false;
		}

		if (temp.inRange(8) && graph[temp.y][temp.x] == 0 && turnTemp <= 2)
		{
			graph[temp.y][temp.x] = -1;

			if (dfs(graph, temp, end, d, turnTemp))
			{
				resetGraph(graph);
				return true;
			}
		}
	}
	resetGraph(graph);
	return false;
}

bool foolproofInput(const vector<vector<int>>& graph, const Point& start, const Point& end)
{
	if (!start.inRange(7) || !end.inRange(7))
		return true;
	if (start == end)
		return true;

	int startNum = graph[start.y][start.x], endNum = graph[end.y][end.x];
	if (startNum != endNum)
		return true;
	if (startNum == 0 || endNum == 0)
		return true;
	return false;
}

int main()
{
	vector<vector<int>> graph(8, vector<int>(8, 0));
	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j < 7; j++)
			cin >> graph[i][j];
	}
	for (Point start, end; cin >> start >> end;)
	{
		if (foolproofInput(graph, start, end))
		{
			cout << "bad pair\n";
			continue;
		}

		// start from every direction
		bool flag = false;
		vector<Point::direction> dirs = {
			Point::direction::UP, 
			Point::direction::DOWN, 
			Point::direction::RIGHT, 
			Point::direction::LEFT 
		};
		for (const auto& d : dirs)
		{
			Point temp = start + start.mapDirection(d);
			if (graph[temp.y][temp.x] == 0)
			{
				graph[temp.y][temp.x] = -1;
				if (dfs(graph, temp, end, d, 0))
					flag = true;
			}
			else if (temp == end)
				flag = true;
		}
		if (flag)
		{
			// clear matched number
			graph[start.y][start.x] = 0;
			graph[end.y][end.x] = 0;
			cout << "pair matched\n";
		}
		else
			cout << "bad pair\n";
	}
	return 0;
}