#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string Generate(string str)
    {
        string result = "";
        int len = str.length(), i = 0;
        while (i < len)
        {
            int j = i + 1;
            while (j < len && str[i] == str[j])
                ++j;
            string count = to_string(j - i);
            result = result + count + str[i];
            i = j;
        }
        return result;
    }
    string countAndSay(int n)
    {
        string out = "1";
        for (int i = 1; i < n; i++)
        {
            out = Generate(out);
        }
        return out;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The " << n << "th term in the count-and-say sequence is: " << sol.countAndSay(n) << endl;
}