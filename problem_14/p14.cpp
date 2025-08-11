#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int Len=strs.size();
        string prefix = "";
        int minLen = strs[0].length();
        for (int i = 1; i < Len; i++) {
            minLen = min(minLen, (int)strs[i].length());
        }
        for (int i = 0; i < minLen; i++) {
            char c = strs[0][i];
            for (int j = 1; j < Len; j++) {
                if (strs[j][i] != c) {
                    return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};
int main()
{
    vector <string> V;
    string str;
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();  // To ignore the newline character after the integer input
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, str);
        V.push_back(str);
    }
    Solution sol;
    cout << "The longest common prefix is: " << sol.longestCommonPrefix(V) << endl;
    return 0;
}