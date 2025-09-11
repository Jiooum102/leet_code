#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> uniqueCount = {1, 1};
        for (int nodes = 2; nodes <= n; nodes++)
        {
            int total = 0;
            for (int root = 1; root <= nodes; root++)
                total += uniqueCount[root - 1] * uniqueCount[nodes - root];
            uniqueCount.push_back(total);
        }
        return uniqueCount[n];
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the number of nodes in the binary search tree: ";
    cin >> n;
    int result = sol.numTrees(n);
    cout << "Number of unique BSTs with " << n << " nodes is: " << result << endl;
    return 0;
}