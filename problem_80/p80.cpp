#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 0; // write index
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (k < 2 || nums[i] != nums[k - 2])
            {
                nums[k++] = nums[i];
            }
        }
        return k;
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