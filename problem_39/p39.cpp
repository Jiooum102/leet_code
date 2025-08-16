#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void generate(vector<vector<int>>& result, vector<int>& ext, vector<int>& nums, int target, int index)
    {
        if(target==0)
            result.push_back(ext);
        for(int i=index;i<nums.size();i++)
        {
            if(nums[i]>target)
                continue;
            ext.push_back(nums[i]);
            generate(result,ext,nums,target-nums[i],i);
            ext.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ext;
        generate(result,ext,candidates,target,0);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> candidates;
    int target,n;
    cout << "Enter number of candidates: ";
    cin >> n;
    candidates.resize(n);
    cout << "Enter the candidates: ";
    for(int i=0;i<n;i++)
    {
        cin >> candidates[i];
    }
    cout << "Enter the target: ";
    cin >> target;

    vector<vector<int>> result = sol.combinationSum(candidates, target);
    cout << "Combinations that sum to " << target << " are:" << endl;
    for(const auto& combination : result)
    {
        for(int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}