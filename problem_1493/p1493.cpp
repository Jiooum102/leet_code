#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        if (nums.size() < 3)
            return max(nums[0], nums[1]);
        vector<pair<int, int>> newVector;
        int index = 0;
        newVector.push_back(make_pair(nums[0], 1));
        int maxLen = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (newVector[index].first == nums[i])
                newVector[index].second++;
            else
            {
                newVector.push_back(make_pair(nums[i], 1));
                index++;
            }
            if (nums[i] > 0)
            {
                if (index > 1 && newVector[index - 1].second < 2)
                {
                    maxLen = max(maxLen, newVector[index].second + newVector[index - 2].second);
                }
                else
                    maxLen = max(maxLen, newVector[index].second);
            }
        }
        if (index < 1)
        {
            if (nums[0] < 1)
                return 0;
            return nums.size() - 1;
        }
        return maxLen;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int result = sol.longestSubarray(nums);
    cout << "The length of the longest subarray is: " << result << endl;
    return 0;
}