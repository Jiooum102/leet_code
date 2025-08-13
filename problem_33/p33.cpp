#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int BinaSrch(vector<int> &nums, int target, int left, int right)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int temp;
        int len = nums.size();
        if (len < 1)
            return -1;
        if (len == 1)
            return nums[0] == target ? 0 : -1;
        for (temp = 1; temp < len; ++temp)
        {
            if (nums[temp - 1] > nums[temp])
                break;
        }
        int find1 = BinaSrch(nums, target, 0, temp - 1);
        int find2 = BinaSrch(nums, target, temp, len - 1);
        if (find1 >= 0)
            return find1;
        if (find2 >= 0)
            return find2;
        return -1;
    }
};
int main()
{
    Solution sol;
    int n, t;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter target element: ";
    cin >> t;
    int result = sol.search(nums, t);
    vector<int> test = {4, 5, 6, 7, 0, 1, 2};
    int result = sol.search(test, 0);
    if (result != -1)
        cout << "Element found at position: " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}