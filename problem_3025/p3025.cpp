#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool ascendingXCompare(vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    }
    int numberOfPairs(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), ascendingXCompare);
        int count = 0, n = points.size();
        for (int i = 0; i < n; i++)
        {
            int mark = -1;
            for (int j = i + 1; j < n; j++)
            {
                if (points[j][1] > points[i][1])
                    continue;
                if (mark < points[j][1])
                {
                    mark = points[j][1];
                    count++;
                    if (mark == points[i][1])
                        break;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter the points (x y) one per line:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }
    int result = sol.numberOfPairs(points);
    cout << "Number of valid pairs: " << result << endl;
    return 0;
}