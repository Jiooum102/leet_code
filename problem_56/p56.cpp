#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int len = intervals.size();
        if (len < 2)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        vector<int> tmp = intervals[0];
        for (int i = 1; i < len; i++)
        {
            if (tmp[1] >= intervals[i][0])
                tmp[1] = max(tmp[1], intervals[i][1]);
            else
            {
                result.push_back(tmp);
                tmp = intervals[i];
            }
        }
        result.push_back(tmp);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals;
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> interval(2);
        cout << "Enter interval " << i + 1 << " (start end): ";
        cin >> interval[0] >> interval[1];
        intervals.push_back(interval);
    }
    vector<vector<int>> merged = sol.merge(intervals);
    cout << "Merged intervals: ";
    for (const auto &interval : merged)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}