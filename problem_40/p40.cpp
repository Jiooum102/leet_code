#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void generate(vector<vector<int>>& result, vector<int>& ext, vector<int>& nums, int target, int index)
    {
        if(target==0)
        {
            if(find(result.begin(), result.end(),ext)==result.end())
                result.push_back(ext);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            if(nums[i]>target)
                break;
            ext.push_back(nums[i]);
            generate(result,ext,nums,target-nums[i],i+1);
            ext.pop_back();
            while(nums.size()-i>1&&nums[i]==nums[i+1])
                    i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
    int n;
    cout << "Enter the number of candidates: ";
    cin >> n;
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        candidates.push_back(x);
    }
    int target;
    cout << "Enter the target sum: ";
    cin >> target;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);
    cout << "The combinations are: " << endl;
    for (const auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}