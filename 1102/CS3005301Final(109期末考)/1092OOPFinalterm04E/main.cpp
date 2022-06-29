#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

bool canTrans(char from, char to, map<char, vector<char>> map)
{
    if (from == to)
    {
        return true;
    }
    if (map.find(from) == map.end())
    {
        return false;
    }
    vector<char> range = map[from];
    for (int index = 0; index < range.size(); index++) {
        if (to == range[index])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int m, n;
    // cin split by space
    // std::getline(std::cin, varName);
    while (std::cin >> m >> n)
    {
        if (m == 0 && n == 0)
        {
            break;
        }
        // process map table
        map<char, vector<char>> config;
        for (int configIndex = 0; configIndex < m; configIndex++)
        {
            char a, b;
            std::cin >> a >> b;
            if (!(a >= 'a' && b <= 'z' && b >= 'a' && b <= 'z'))
            {
                std::cout << "ERROR" << std::endl;
                continue;
            }
            if (config.find(a) != config.end()) {
                config.at(a).push_back(b);
            }
            else {
                vector<char> newList;
                newList.push_back(b);
                config.insert_or_assign(a, newList);
            }
        }
        // parser
        std::string a, b;
        int status = 0; // 0 => yes, 1 => on, 2=> error
        for (int transWord = 0; transWord < n; transWord++) {
            std::cin >> a >> b;
            if (a.size() != b.size())
            {
                std::cout << "no" << std::endl;
                continue;
            }
            for (int index = 0; index < a.size(); index++)
            {
                if (!(a[index] >= 'a' && b[index] <= 'z' && b[index] >= 'a' && b[index] <= 'z'))
                {
                    std::cout << "ERROR" << std::endl;
                    status = 2;
                    break;
                }
                vector<char> used;
                if (!canTrans(a[index], b[index], config)) {
                    status = 1;
                    break;
                }
            }
            if (status == 0) {
                std::cout << "yes" << std::endl;
            }
            else if (status == 1)
            {
                std::cout << "no" << std::endl;
            }
        }
    }
    return 0;
}


/*
3 4
a c
b a
a b
aaa abc
abc aaa
acm bcm
a3 bb
*/