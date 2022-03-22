//// Name: ¤ý¥¿§»
//// Date: March 08, 2022
//// Last Update: March 08, 2022
//// Problem statement: Simple Drawing Program
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//class Point {
//	public:
//	Point(int x, int y) : x(x), y(y) {}
//	int x, y;
//	bool operator==(const Point& lhs, const Point& rhs);
//};
//bool Point::operator==(const Point& lhs, const Point& rhs) {
//	return lhs.x == rhs.x && lhs.y == rhs.y;
//}
//
///*
//***************************************
//* Draw Class(root)
//***************************************
//*/
//class Draw {
//public:
//	Draw(int width, int height) : width(width), height(height)
//	{
//		for (int row = 0; row < height; row++) {
//			vector<string> cache;
//			for (int col = 0; col < width; col++) {
//				cache.push_back("*");
//			}
//			records.push_back(cache);
//		}
//	}
//	
//	vector<vector<string>> records;
//	bool task(string input);
//	void printMap();
//	vector<string> split(string str, char splitBy);
//	int width{ 0 }, height{ 0 };
//};
//
//class Square : Draw {
//public:
//	Square(int width, int height, vector<string> input) : Draw(width, height)
//	{
//		// S <w> <x> <y>
//		config["type"] = input[0];
//		config["w"] = input[1];
//		config["x"] = input[2];
//		config["y"] = input[3];
//	}
//	bool authCheck();
//	void process();
//	map<string, string> config;
//};
//
//class Triangle : Draw {
//public:
//	Triangle(int width, int height, vector<string> input) : Draw(width, height)
//	{
//		// T <w> <x> <y> <LU / LD / RU / RD>
//		config["type"] = input[0];
//		config["w"] = input[1];
//		config["x"] = input[2];
//		config["y"] = input[3];
//		config["side"] = input[4];
//		/*
//		|------LU------ ------LD------ ------RU------ ------RD------
//		|
//		|       c      |   a ---- b  |     c        |    b ---- a
//		|	    -      |      ---    |     -		|      ---
//		|	   --      |       --    |     --	    |      --
//		|	  ---      |        -	 |     ---	    |      -
//		|  a ---- b    |        c	 |   b ----- a  |	   c
//		|-----------------------------------------------------------
//		*/
//
//		// update point information
//		// point A
//		if (config["side"][0] == 'L') {
//			points["a"]["x"] = stoi(config["x"]) - (stoi(config["w"]) - 1);
//			points["a"]["y"] = stoi(config["y"]);
//		}
//		else if (config["side"][0] == 'R') {
//			points["a"]["x"] = stoi(config["x"]) + (stoi(config["w"]) - 1);
//			points["a"]["y"] = stoi(config["y"]);
//		}
//		// point B
//		points["b"]["x"] = stoi(config["x"]);
//		points["b"]["y"] = stoi(config["y"]);
//		// point C
//		if (config["side"][1] == 'U') {
//			points["c"]["x"] = stoi(config["x"]);
//			points["c"]["y"] = stoi(config["y"]) - (stoi(config["w"]) - 1);
//		}
//		else if (config["side"][1] == 'D') {
//			points["c"]["x"] = stoi(config["x"]);
//			points["c"]["y"] = stoi(config["y"]) + (stoi(config["w"]) - 1);
//		}
//	}
//
//	map<string, string> config;
//	map<string, map<string, int>> points;
//	void process();
//	bool authCheck();
//};
//
//vector<string> Draw::split(string str, char splitBy) {
//	vector<string> result;
//	vector<char> charArr(str.begin(), str.end());
//	string cache = "";
//	for (int index = 0; index < str.size(); index++) {
//		if (charArr[index] == splitBy && cache != "") {
//			result.push_back(cache);
//			cache = "";
//		}
//		else {
//			cache += charArr[index];
//		}
//	}
//	if (cache != "") {
//		result.push_back(cache);
//	}
//	return result;
//}
//bool Draw::task(string input) {
//	vector<string> config = split(input, ' ');
//	if (config[0] == "S") {
//		Square obj{ width, height, split(input, ' ') };
//		if (obj.authCheck()) {
//			obj.process();
//			return true;
//		}
//	}
//	else if (config[0] == "T") {
//		Triangle obj{ width, height, split(input, ' ') };
//		if (obj.authCheck()) {
//			obj.process();
//			return true;
//		}
//	}
//	else if (config[0] == "L") {
//
//	}
//	return false;
//}
//void Draw::printMap() {
//	for (int row = 0; row < height; row++) {
//		for (int col = 0; col < width; col++) {
//
//			cout << records[row][col];
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//bool Square::authCheck() {
//	// S <w> <x> <y>
//	return (
//		stoi(config["x"]) >= 0 &&
//		stoi(config["y"]) >= 0 &&
//		stoi(config["x"]) + stoi(config["w"]) < width &&
//		stoi(config["y"]) + stoi(config["w"]) < height
//		);
//}
//void Square::process() {
//	// S <w> <x> <y>
//	for (int row = 0; row < height; row++) {
//		for (int col = 0; col < width; col++) {
//			if (
//				row >= stoi(config["y"]) &&
//				row < (stoi(config["y"]) + stoi(config["w"])) &&
//				col >= stoi(config["x"]) &&
//				col < (stoi(config["x"]) + stoi(config["w"]))
//				) {
//				records[row][col] = "X";
//			}
//			cout << records[row][col];
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//bool Triangle::authCheck() {
//	// T <w> <x> <y> <LU / LD / RU / RD>
//	// LU => left up
//	// LD => left down
//	// RU => right up
//	// RD => right down
//
//	/*
//	|------LU------ ------LD------ ------RU------ ------RD------
//	|
//	|       c       |   a ---- b  |     c        |    b ---- a
//	|	    -       |      ---    |     -		 |      ---
//	|	   --       |       --    |     --		 |      --
//	|	  ---       |        -	  |     ---	     |      -
//	|  a ---- b     |        c	  |   b ----- a  |		c
//	|-----------------------------------------------------------
//	*/
//	
//	bool typeInAuthList = false;
//	int width = stoi(config["w"]);
//	string authTypeList[] = { "LU", "LD", "RU", "RD" };
//	
//	// check side type
//	for (auto& item : authTypeList) {
//		if (config["side"] == item) {
//			typeInAuthList = true;
//		}
//	}
//	if (!typeInAuthList) {
//		return false;
//	}
//	
//	// check every point are valid
//	for (auto& item : points) {
//		if (
//			item.second["x"] < 0 || 
//			item.second["x"] >= width || 
//			item.second["y"] < 0 || 
//			item.second["y"] >= height
//		) {
//			return false;
//		}
//	}
//	
//	return true;
//}
//void Triangle::process() {
//	// T <w> <x> <y> <LU/LD/RU/RD>
//	records[points["b"]["y"]][points["b"]["x"]] = "X";
//	if (config["w"] !=  "1"){
//		int widthNow = stoi(config["w"]);
//		//// up
//		//if (config["side"][1] == 'U') {
//		//	for (int row = points["b"]["y"]; row >= points["c"]["y"]; row--) {
//		//		// LU
//		//		if (config["side"][0] == 'L') {
//		//			for (int col = widthNow - 1; col >= 0; col--) {
//		//				// fill a => b
//		//				records[row][points["b"]["x"] - col] = "X";
//		//			}
//		//			widthNow--;
//		//		}
//		//		// RU
//		//		else if (config["side"][0] == 'R') {
//		//			for (int col = 0; col <= widthNow - 1; col++) {
//		//				// fill b => a
//		//				records[row][points["b"]["x"] + col] = "X";
//		//			}
//		//		}
//		//	}
//		//} 
//		//// down
//		//else if (config["side"][1] == 'D') {
//		//	for (int row = points["b"]["y"]; row <= points["c"]["y"]; row++) {
//		//		// LD
//		//		if (config["side"][0] == 'L') {
//		//			// fill a => b
//		//			for (int col = widthNow - 1; col >= 0; col--) {
//		//				records[row][points["b"]["x"] - col] = "X";
//		//			}
//		//		}
//		//		// RD
//		//		if (config["side"][0] == 'R') {
//		//			for (int col = 0; col <= widthNow - 1; col++) {
//		//				// fill b => a
//		//				records[row][points["b"]["x"] + col] = "X";
//		//			}
//		//		}
//		//	}
//		//}
//	
//		auto a = Point{points["a"]["x"], points["a"]["y"]};
//		auto b = Point{points["b"]["x"], points["b"]["y"]};
//		auto c = Point{points["c"]["x"], points["c"]["y"]};
//
//		// LU LD RU RD
//		// LU
//		// row is y, col is x
//
//		for (Point start = a, end = b; start != end; start.y--, start.x++, end.y--) {
//			for (Point p = start; p.x != end.x; p.x++) {
//				records[y][x] = "X";
//			}
//		}
//	}
//
//	// print
//	printMap();
//}
//
//
///*
//„«	L <x1> <y1> <x2> <y2>
//*/
//
//
//int main() {
//	int width, height;
//	cin >> width;
//	cin >> height;
//	Draw draw{ width, height };
//	
//	string input;
//	while (getline(cin, input)) {
//		if (input.length() > 4) {
//			if (draw.split(input, ' ')[0] == "EXIT") {
//				break;
//			}
//			else {
//				if (!draw.task(input)) {
//					cout << "Out of range." << endl;
//				}
//			}
//		}
//	}
//	
//}