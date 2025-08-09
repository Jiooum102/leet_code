#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        long long closestSum = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                long long currentSum = nums[i] + nums[left] + nums[right];
                if (abs(currentSum - target) < abs(closestSum - target))
                {
                    closestSum = currentSum;
                }
                if (currentSum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return closestSum;
    }
};
int main()
{
    int n;
    vector<int> nums;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << "Enter target sum: ";
    int target;
    cin >> target;
    Solution sol;
    int result = sol.threeSumClosest(nums, target);
    cout << "Closest sum is: " << result << endl;
    return 0;
}