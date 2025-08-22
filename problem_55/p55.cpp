#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
            return true;
        int Max=0;
        for(int i=0;i<=Max;i++)
        {
            Max=max(Max,i+nums[i]);
            if(Max>len-2)
                return true;
        }
        return false;
    }
};
int main() {
    Solution sol;
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << (sol.canJump(nums) ? "true" : "false") << endl;
    return 0;
}