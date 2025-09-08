#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    // Check whether the string is valid
    bool valid(string temp)
    {
        if (temp.size() > 3 || temp.size() == 0)
            return false;
        if (temp.size() > 1 && temp[0] == '0')
            return false;
        if (temp.size() && stoi(temp) > 255)
            return false;
        return true;
    }

    // Generating using backtracking
    void generate(vector<string> &ans, string output, int ind, string s, int dots)
    {
        if (dots == 3)
        { // The maximum number of dots is 3
            if (valid(s.substr(ind)))
                ans.push_back(output + s.substr(ind));
            return;
        }
        int sz = s.size();
        for (int i = ind; i < min(ind + 3, sz); i++)
        {
            if (valid(s.substr(ind, i - ind + 1)))
            {
                output.push_back(s[i]);
                output.push_back('.');
                generate(ans, output, i + 1, s, dots + 1); // backtrack
                output.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        string res;
        generate(ans, res, 0, s, 0);
        return ans;
    }
};

int main()
{
    Solution sol;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    vector<string> ans = sol.restoreIpAddresses(s);
    cout << "The valid IP addresses are: " << endl;
    for (auto &ip : ans)
    {
        cout << ip << endl;
    }
    return 0;
}