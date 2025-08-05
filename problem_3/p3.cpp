#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    bool check[256] = {false};
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int n = s.size(), head = 0, maxLen = 0;
    for(int i = 0; i < n; i++)
    {
        if(check[s[i]] == false)
        {
            check[s[i]] = true;
            maxLen = max(maxLen, i - head + 1);
        }
        else
        {
            while(s[head] != s[i])
            {
                check[s[head]] = false;
                head++;
            }
            head++;
        }
    }
    cout << "Maximum length of substring without repeating characters: " << maxLen << endl;
    return 0;
}