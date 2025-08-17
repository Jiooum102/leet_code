#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n;i++)
        {
            int temp=nums[i];
            while(temp>0&&temp<=n&&temp!=nums[temp-1])
            {
                swap(nums[i],nums[temp-1]);
                temp=nums[i];
            }
        }
        for(int i=0;i<n;)
            if(nums[i]!=++i)
                return i;
        return n+1;
    }
};
int main()
{
    Solution sol;
    vector<int> nums;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int result = sol.firstMissingPositive(nums);
    cout << "The first missing positive integer is: " << result << endl;
    return 0;
}