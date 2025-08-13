#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        vector<int> New = nums;
        sort(New.begin(), New.end());
        for (int i = 0; i < New.size(); i++)
            for (int j = i + 1; j < New.size(); j++)
                for (int k = j + 1; k < New.size(); k++)
                {
                    long long last = (long long)target - (long long)New[i] - (long long)New[j] - (long long)New[k];
                    if (last < New[k])
                        continue; // No valid quadruplet can be formed
                    auto it = lower_bound(New.begin() + k + 1, New.end(), last);
                    if (it != New.end() && *it == last)
                    {
                        vector<int> quad = {New[i], New[j], New[k], (int)last};
                        if (result.empty() || find(result.begin(), result.end(), quad) == result.end())
                        {
                            result.push_back(quad);
                        }
                    }
                }
        return result;
    }
};
int main()
{
    Solution sol;
    vector<int> nums;
    int target, n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << "Enter the target sum: ";
    cin >> target;
    vector<vector<int>> result = sol.fourSum(nums, target);
    cout << "Quadruplets that sum to " << target << " are: " << endl;
    for (auto &quad : result)
    {
        cout << "[ ";
        for (int i = 0; i < quad.size(); i++)
        {
            cout << quad[i];
            if (i < quad.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}