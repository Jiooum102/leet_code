#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.length() > s.length() || t.empty() || s.empty())
            return "";
        int n = s.length(), m = t.length();
        vector<int> charCount(256, 0);
        for (int i = 0; i < m; i++)
            charCount[t[i]]++;
        int cnt = 0, l = 0, minLen = INT_MAX, startIndex = -1;
        for (int r = 0; r < s.length(); r++)
        {
            if (charCount[s[r]] > 0)
                cnt++;
            charCount[s[r]]--;
            while (cnt == m)
            {
                if (r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    startIndex = l;
                }
                charCount[s[l]]++;
                if (charCount[s[l]] > 0)
                    cnt--;
                l++;
            }
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};

int main()
{
    Solution sol;
    string s, t;
    cout << "Enter the main string (s): ";
    cin >> s;
    cout << "Enter the pattern string (t): ";
    cin >> t;
    string result = sol.minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;
    return 0;
}