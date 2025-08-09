#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        map <int, int> Map;
        for(auto num : nums) {
            Map[num]++;
        }
        for(auto it1 = Map.begin(); it1 != Map.end(); it1++) {
            if(it1->second>2)
                if(it1->first == 0) {
                    result.push_back({0, 0, 0});
                }
            if(it1->second>1)
            {
                auto it2 = Map.find(-2 * it1->first);
                if(it2 != Map.end())
                {
                    if(it2->first > it1->first)
                    {
                        result.push_back({it1->first, it1->first, it2->first});
                    }
                }
            }
            for(auto it2 = next(it1); it2 != Map.end(); it2++)
            {
                if(it2->second>1&& it1->first + 2*it2->first == 0)
                {
                    result.push_back({it1->first, it2->first, it2->first});
                    break;
                }
                auto it3 = Map.find(-(it1->first + it2->first));
                if(it3 != Map.end() && it3->first > it2->first)
                {
                    result.push_back({it1->first, it2->first, it3->first});
                }
            }
        }
        return result;
    }
};
int main()
{
    int n;
    vector<int> Arr;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Arr.push_back(x);
    }
    Solution sol;
    vector<vector<int>> result = sol.threeSum(Arr);
    cout << "Triplets are: " << endl;
    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    return 0;
}