#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void back_track(vector<vector<int>> &result, vector<int> nums, int index, vector<int> &tmp)
    {
        int len = nums.size();
        if (index == len)
        {
            result.push_back(tmp);
            return;
        }

        tmp.push_back(nums[index]);
        back_track(result, nums, index + 1, tmp);
        tmp.pop_back();

        while (index + 1 < len && nums[index] == nums[index + 1])
        {
            index++;
        }

        back_track(result, nums, index + 1, tmp);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        back_track(result, nums, 0, tmp);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<vector<int>> result = sol.subsetsWithDup(nums);
    cout << "The subsets are: " << endl;
    for (auto &subset : result)
    {
        cout << "[ ";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ", ";
        }
        cout << " ]" << endl;
    }
    return 0;
}