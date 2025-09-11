#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int len = heights.size();
        if (len == 0)
            return 0;
        vector<int> left(len), right(len);
        // Find nearest smaller number on the left
        left[0] = -1;
        for (int i = 1; i < len; ++i)
        {
            int tmp = i - 1;
            while (tmp >= 0 && heights[i] <= heights[tmp])
            {
                tmp = left[tmp];
            }
            left[i] = tmp;
        }
        // Find nearest smaller number on the right
        right[len - 1] = len;
        for (int i = len - 2; i >= 0; --i)
        {
            int tmp = i + 1;
            while (tmp < len && heights[i] <= heights[tmp])
            {
                tmp = right[tmp];
            }
            right[i] = tmp;
        }
        int maxArea = 0;
        for (int i = 0; i < len; ++i)
        {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<int> heights;
    int n;
    cout << "Enter number of bars in the histogram: ";
    cin >> n;
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        heights.push_back(h);
    }
    int maxArea = sol.largestRectangleArea(heights);
    cout << "Largest rectangle area: " << maxArea << endl;
    return 0;
}