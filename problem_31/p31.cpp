#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index;
        for(index = nums.size()-1; index>0; index--)
        {
            if(nums[index]>nums[index-1])
                break;
        }
        if(index<1)
            reverse(nums,0);
        else
        {
            index--;
            for(int i = nums.size()-1;i>index;i--)
            {
                if(nums[i]>nums[index])
                {
                    swapInt(nums[i],nums[index]);
                    reverse(nums,index+1);
                    break;
                }
            }
        }
    }
    void swapInt(int &a, int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    void reverse(vector<int>& nums, int left)
    {
        if(nums.size()-left<2)
            return;
        int tmpl=left,tmpr=nums.size()-1;
        while(tmpl<tmpr)
        {
            swapInt(nums[tmpl],nums[tmpr]);
            tmpl++;
            tmpr--;
        }
    }
};
int main()
{
    Solution sol;
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sol.nextPermutation(nums);
    cout << "Next permutation: ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}