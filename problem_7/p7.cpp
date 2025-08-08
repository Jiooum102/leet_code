#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int tmp = x, rx = 0;
        while (tmp != 0) {
            int digit = tmp % 10;
            if (rx > (INT_MAX) / 10) {
                return 0; // Handle overflow
            }
            if (rx < (INT_MIN) / 10) {
                return 0; // Handle underflow
            }
            rx = rx * 10 + digit;
            tmp /= 10;
        }
        return rx;
    }
};
int main()
{
    int x;
    cout << "Enter integer: ";
    cin >> x;
    Solution sol;
    int result = sol.reverse(x);
    cout << "Reversed integer: " << result << endl;
    return 0;
}