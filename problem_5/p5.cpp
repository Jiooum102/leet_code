#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string str;
    int Len,maxLen = 0;
    cout << "Enter string: ";
    cin >> str;
    Len = str.length();
    for(int i = 0; i < Len; i++)
    {
        for(int j=Len-1; j >= i+maxLen; j--)
        {
            if(str[i] == str[j])
            {
                int k = 0;
                while(i+k < j-k && str[i+k] == str[j-k])
                {
                    k++;
                }
                if(i+k >= j-k)
                {
                    maxLen = max(maxLen, j-i+1);
                    break;
                }
            }
        }
    }
    cout << "Length of longest palindromic substring: " << maxLen << endl;
    return 0;
}