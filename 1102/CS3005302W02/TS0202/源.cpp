// Name: ¤ý¥¿§»
// Date: February 27, 2022
// Last Update: February 27, 2022
// Problem statement: Computes the average and standard deviation
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <algorithm> // sort

using namespace std;
using std::stoi;
using std::reverse;
using std::to_string;
using std::endl;

string fileName = "./scores.txt";
void getHighScores(vector<string> name, vector<int> score) {
    vector<map<string, string>> config;
    for (int index = 0; index < name.size(); index++) {
        map<string, string> cache;
        cache["name"] = name[index];
        cache["score"] = to_string(score[index]);
        config.push_back(cache);
    }
    sort(
        config.begin(), 
        config.end(), 
        [](map<string, string> x, map<string, string> y) {
            return stoi(x["score"]) < stoi(y["score"]);
        }
    );
    reverse(config.begin(), config.end());

    for (int index = 0; index < 3; index++) {
        std::cout
            << config[index]["name"]
            << "\n"
            << config[index]["score"]
            << endl;
    }
}
int main() 
{
    string line;
    ifstream file(fileName);
    vector<string> names;
    vector<int> scores;
    if (file.is_open())
    {
        int index = 0;
        while (getline(file, line))
        {
            bool isScore = index % 2 != 0;
            if (isScore) {
                scores.push_back(stoi(line));
            }
            else {
                names.push_back(line);
            }
            index++;
        }
        getHighScores(names, scores);
        file.close();
    }

	return 0;
}