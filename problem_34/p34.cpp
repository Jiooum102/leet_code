#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int BinaSrch(vector<int>& nums, int target)
    {
        if(nums.size()<1)
            return -1;
        if(target<nums[0]||target>nums[nums.size()-1])
            return -1;
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                right=mid-1;
            else
                left=mid+1;
        }
        return -1;
    }
    vector<int> Search(vector<int>& nums, int pos)
    {
        int left=pos,right=pos;
        while(left>0&&nums[left]==nums[left-1])
            left--;
        while(right<nums.size()-1&&nums[right]==nums[right+1])
            right++;
        vector <int> result;
        result.push_back(left);
        result.push_back(right);
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> result;
        int pos=BinaSrch(nums,target);
        if(pos==-1)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        return Search(nums,pos);
    }
};
int main()
{
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cout << "Enter target element: ";
    cin >> target;
    vector<int> result = sol.searchRange(nums, target);
    cout << "Result: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}