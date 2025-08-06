#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int p
int main()
{
    string str;
    int Len;
    cout << "Enter string: ";
    cin >> str;
    Len = str.length();
    map<char, vector<int>> Map;
    for (int i = 0; i < Len; i++)
    {
        Map[str[i]].push_back(i);
    }
    int maxLen = 0,temp;
    for(const auto& pair : Map)
    {
        temp = Map[pair.first].last() - Map[pair.first].front() + 1;
        if(temp > maxLen)
        {
            maxLen = temp;
        }
    }

}