#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int Len = s.length();
        if (numRows <= 1 || numRows >= Len) {
            return s;
        }
        string result = "";
        int div = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < Len; j += div) {
                result += s[j];
                if (i > 0 && i < numRows - 1) {
                    int midIndex = j + div - 2 * i;
                    if (midIndex < Len) {
                        result += s[midIndex];
                    }
                }
            }
        }
        return result;
    }
};
int main()
{
    Solution sol;
    string str;
    cout << "Enter string: ";
    cin >> str;
    int Len = str.length();
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;
    string result = sol.convert(str, numRows);
    cout << "Converted string: " << result << endl;
    return 0;
}