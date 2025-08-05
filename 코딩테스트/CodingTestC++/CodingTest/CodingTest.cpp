#include <iostream>
#include <unordered_map>
using namespace std;

string Solution(const string str)
{
    unordered_map<char, int> map;

    for (int i = 0; i < str.length(); i++)
    {
        map[str[i]] = i;
    }

    string result;
    

    for (int i = 0; i < str.length(); i++)
    {
        if (map[str[i]] == i)
        {
            result.push_back(str[i]);
        }
    }

    return result;
}
int main()
{
    cout << Solution("BaNana");
}
