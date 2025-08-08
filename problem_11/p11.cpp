#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int Len = height.size();
        if (Len < 2)
            return 0;
        int maxArea = 0;
        int left = 0, right = Len - 1;
        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};
int main()
{
    Solution sol;
    vector<int> height;
    int Len;
    cout << "Enter number of elements: ";
    cin >> Len;
    cout << "Enter elements: ";
    for (int i = 0; i < Len; i++)
    {
        int tmp;
        cin >> tmp;
        height.push_back(tmp);
    }
    cout << "Max area: " << sol.maxArea(height) << endl;
    return 0;
}