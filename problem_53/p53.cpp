#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN;
        int tmpSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            tmpSum += nums[i];

            if (tmpSum > maxSum)
            {
                maxSum = tmpSum;
            }

            if (tmpSum < 0)
            {
                tmpSum = 0;
            }
        }

        return maxSum;
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
    int result = sol.maxSubArray(nums);
    cout << "Maximum subarray sum: " << result << endl;
    return 0;
}