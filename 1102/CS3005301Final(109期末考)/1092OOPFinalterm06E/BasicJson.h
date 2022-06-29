#include <array> // array
#include <forward_list> // forward_list
#include <iterator> // inserter, front_inserter, end
#include <map> // map
#include <string> // string
#include <tuple> // tuple, make_tuple
#include <type_traits> // is_arithmetic, is_same, is_enum, underlying_type, is_convertible
#include <unordered_map> // unordered_map
#include <valarray> // valarray

#include <numeric> // accumulate
#include <utility> // declval, forward, move, pair, swap
#include <vector> // vector

#include <algorithm> // all_of, find, for_each

#include <fstream>
#include <list>
#include <deque>
class BasicJson {
public:
    BasicJson() {};
    std::map<int, std::map<std::string, std::string>>& operator[] ();
    bool Parse(std::string);
    void Write(std::string OutputFileName);
    void Delete(std::string Name);
    float TotalArea();
private:
    std::fstream file;
    std::map<int, std::map<std::string, std::string>> result;

};
std::map<int, std::map<std::string, std::string>>& BasicJson::operator[] ()
{
    return result;
}
bool BasicJson::Parse(std::string) {

    return true;
}

void BasicJson::Write(std::string OutputFileName) {

}

void BasicJson::Delete(std::string Name) {

}
float BasicJson::TotalArea() {
    return 0;
}