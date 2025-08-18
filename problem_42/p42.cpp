#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        int *LTR = new int[len];
        int *RTL = new int[len];
        int Max = 0;
        for (int i = 0; i < len; i++)
        {
            Max = max(Max, height[i]);
            LTR[i] = Max;
        }
        Max = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            Max = max(Max, height[i]);
            RTL[i] = Max;
        }
        int total = 0;
        for (int i = 0; i < len; i++)
        {
            int tmp = min(LTR[i], RTL[i]);
            total = total + (tmp - height[i]);
        }
        return total;
    }
};
int main()
{
    Solution sol;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> height[i];
    int result = sol.trap(height);
    cout << "Trapped rainwater: " << result << endl;
    return 0;
}