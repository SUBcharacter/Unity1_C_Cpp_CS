#include <iostream>
#include <unordered_map>
using namespace std;

string Solution(const string str)
{
    unordered_map<char, int> map;

    for (int i = 0; i < str.length(); i++)
    {
        if (map.find(str[i]) == map.end())
        {
            map[str[i]] = i;
        }
    }

    string result;

    for (auto m : map)
    {
        result.push_back(m.first);
    }

    return result;
}
int main()
{
    cout << Solution("static");
}
