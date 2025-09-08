#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        int len = nums.size();
        for (int k = 0; k <= len; k++) {
            vector<int> combination(k);
            for (int i = 0; i < k; i++) {
                combination[i] = i ;
            }
            while (true) {
                vector<int> tmp;
                for(int j=0;j<k;j++)
                {
                    tmp.push_back(nums[combination[j]]);
                }
                out.push_back(tmp);
                int index = k - 1;
                while (index >= 0 && combination[index] == len + index - k) {
                    index--;
                }
                if (index < 0)
                    break;
                combination[index]++;
                for (int j = index + 1; j < k; j++)
                    combination[j] = combination[j - 1] + 1;
            }
        }
            return out;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<vector<int>> result = sol.subsets(nums);
    cout << "All subsets: " << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}