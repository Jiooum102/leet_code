#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int len = nums.size();
        int *arr = new int[len];
        int nextend = 0, farthestend = 0, step = 0;
        for (int i = 0; i < len; i++)
        {
            farthestend = max(farthestend, i + nums[i]);
            arr[i] = step;
            if (i == nextend)
            {
                nextend = farthestend;
                step++;
            }
        }
        return arr[len - 1];
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
    int result = sol.jump(nums);
    cout << "Minimum jumps required: " << result << endl;
    return 0;
}
