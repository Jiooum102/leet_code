#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isLast(vector<int> nums, int len)
    {
        for (int i = 1; i < len; i++)
            if (nums[i] > nums[i - 1])
                return false;
        return true;
    }
    void reverse(vector<int> &nums, int head, int tail)
    {
        int l = head, r = tail;
        while (l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
    void Generate(vector<vector<int>> &result, vector<int> &nums, int len)
    {
        while (!isLast(nums, len))
        {
            for (int i = len - 1; i > 0; i--)
            {
                if (nums[i] > nums[i - 1])
                {
                    int j = len - 1;
                    while (nums[j] < nums[i - 1] && j > 0)
                        j--;
                    swap(nums[i - 1], nums[j]);
                    reverse(nums, i, len - 1);
                    result.push_back(nums);
                    break;
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        result.push_back(nums);
        if (nums.size() < 2)
        {
            return result;
        }
        Generate(result, nums, nums.size());
        return result;
    }
};
int main()
{
    Solution sol;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> result = sol.permute(nums);
    cout << "All permutations: " << endl;
    for (const auto &perm : result)
    {
        for (int num : perm)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}