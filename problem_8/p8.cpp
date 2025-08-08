#include <iostream>
#include <string>
#include <limits.h>
#include <cmath>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int Len = s.length();
        if (Len == 0) {
            return 0;
        }
        int i = 0;
        while (i < Len && s[i] == ' ') {
            i++;
        }
        if (i == Len) {
            return 0;
        }
        bool isNegative = false;
        if (s[i] == '-') {
            isNegative = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        long long result = 0;
        while (i < Len && s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
            if (result > INT_MAX) {
                return isNegative ? INT_MIN : INT_MAX;
            }
            i++;
        }
        return isNegative ? -result : result;
    }
};
int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);
    Solution sol;
    int result = sol.myAtoi(str);
    cout << "Converted integer: " << result << endl;
    return 0;
}