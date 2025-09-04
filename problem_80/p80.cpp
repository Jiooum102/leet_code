#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();
        int count = 2;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            while (i < nums.size() - 1 && nums[i - 1] == nums[i] && nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i);
            }
        }
        return nums.size();
    }
};
int main()
{
    Solution sol;
    vector<int> nums;
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int k = sol.removeDuplicates(nums);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}