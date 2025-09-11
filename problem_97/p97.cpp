#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        // Check whether size of s3 is equal to sum of sizes of s1 and s2
        if (s1.size() + s2.size() != s3.size())
            return false;
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        // Create (n1 + 1) * (n2 + 1) to mark if strings can be created
        // The first string would be "" which means there's no character in it
        dp[0][0] = true;
        // Iterate whether a character in s1 can be placed in same place in s3
        for (int i = 1; i <= n2; ++i)
            dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
        // Do the same with s2
        for (int i = 1; i <= n1; ++i)
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];

        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                // If the previous string exists and the current character is the same as the character in s3
                // Then we mark this string as exists
                if (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = true;
                else if (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = true;
            }
        }
        return dp.back().back();
    }
};

int main()
{
    Solution sol;
    string s1, s2, s3;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    cout << "Enter third string: ";
    cin >> s3;

    bool result = sol.isInterleave(s1, s2, s3);
    cout << (result ? "Yes, the third string is an interleaving of the first two." : "No, it is not an interleaving.") << endl;

    return 0;
}