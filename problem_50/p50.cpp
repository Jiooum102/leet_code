#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
            if (n > 0)
                return 0;
            else
                return 1;
        string tmp = "";
        long long bin = abs((long long)n);
        while (bin > 0)
        {
            if (bin % 2 == 0)
                tmp = "0" + tmp;
            else
                tmp = "1" + tmp;
            bin /= 2;
        }
        double res = 1;
        for (int i = tmp.length() - 1; i >= 0; i--)
        {
            if (tmp[i] == '1')
                res *= x;
            x = x * x;
        }
        return (n > 0) ? res : 1 / res;
    }
};
int main()
{
    Solution sol;
    double x;
    int n;
    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;
    double result = sol.myPow(x, n);
    cout << "Result: " << result << endl;
    return 0;
}