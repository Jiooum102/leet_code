#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len=nums.size();
        int head=0,tail=len-1;
        while(head<tail)
        {
            while(head<len&&nums[head]<1)
                head++;
            while(tail>head&&nums[tail]>0)
                tail--;
            if(head<tail)
            {
                swap(nums[head],nums[tail]);
                head++;
                tail--;
            }            
        }
        head=0; tail=len-1;
        while(head<tail)
        {
            while(head<len&&nums[head]<2)
                head++;
            if(head==len)
                break;
            while(tail>head&&nums[tail]>1)
                tail--;
            if(head<tail)
            {
                swap(nums[head],nums[tail]);
                head++;
                tail--;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements (0, 1, 2): ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    sol.sortColors(nums);
    cout << "Sorted colors: ";
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}