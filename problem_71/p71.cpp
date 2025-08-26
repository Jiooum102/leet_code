#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        string out = "";
        int backcount = 0;
        for (int i = path.length() - 1; i > 0; i--)
        {
            if (path[i] != '/')
            {
                for (int j = i - 1; j >= 0; j--)
                    if (path[j] == '/')
                    {
                        string tmp = path.substr(j + 1, i - j);
                        if (tmp != ".")
                            if (tmp == "..")
                            {
                                backcount++;
                            }
                            else if (backcount > 0)
                            {
                                backcount--;
                            }
                            else
                                out = "/" + tmp + out;
                        i = j;
                        break;
                    }
            }
        }
        if (out.length() < 1)
            return "/";
        return out;
    }
};

int main()
{
    Solution sol;
    string path;
    cout << "Enter the path: ";
    cin >> path;

    string result = sol.simplifyPath(path);
    cout << "Simplified path: " << result << endl;

    return 0;
}