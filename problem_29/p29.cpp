#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1)
            return dividend;
        if(divisor==-1)
        {
            if(dividend==INT_MIN)
                return INT_MAX;
            return -dividend;
        }
        return dividend/divisor;
    }
};
int main()
{
    int dividend, divisor;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;
    Solution sol;
    int result = sol.divide(dividend, divisor);
    cout << "Result: " << result << endl;
    return 0;
}