#include <iostream>

using namespace std;

class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        for (int k = 1; k <= 60; k++)
        {
            // If there are k operations, we have fomula below
            // num1 - k * num2 = x = pow(2,i1) + pow(2,i2) + ...
            long long x = num1 - 1LL * num2 * k;
            // x must be equal or larger than k to perform
            // k times pow(2,0) or larger.
            if (x < k)
            {
                return -1;
            }
            // Then, in binary performance of x, the number of bit 1 have to be
            // equal or smaller than k to perform k operations.
            if (k >= __builtin_popcountll(x))
            {
                return k;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int num1, num2;
    cout << "Enter num1: ";
    cin >> num1;
    cout << "Enter num2: ";
    cin >> num2;
    int result = sol.makeTheIntegerZero(num1, num2);
    if(result != -1)
        cout << "Minimum operations to make integer zero: " << result << endl;
    else
        cout << "It's not possible to make the integer zero with given num1 and num2." << endl;
    return 0;
}