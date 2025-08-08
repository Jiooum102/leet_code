#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        int Roman1[] = {1000, 100, 10, 1};
        string Char1[] = {"M", "C", "X", "I", "D", "L", "V"};
        string result = "";
        for (int i = 0; i < 4; i++) {
            int tmp = num / Roman1[i];
            num %= Roman1[i];
            if(i<1)
            {
                while(tmp--) {
                    result += Char1[i];
                }
            }
            else
            {
                if(tmp<4)
                {
                    while(tmp--)
                    {
                        result += Char1[i];
                    }
                }
                else if(tmp==4)
                {
                    result += Char1[i] + Char1[i+3];
                }
                else if(tmp==5)
                {
                    result += Char1[i+3];
                }
                else if(tmp<9)
                {
                    result += Char1[i+3];
                    while(tmp-- > 5) {
                        result += Char1[i];
                    }
                }
                else
                {
                    result += Char1[i] + Char1[i-1];
                }
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    int num;
    cout << "Enter integer: ";
    cin >> num;
    string roman = sol.intToRoman(num);
    cout << "Roman numeral: " << roman << endl;
    return 0;
}