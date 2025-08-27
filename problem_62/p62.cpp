#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int **arr = new int *[m];
        for (int i = 0; i < m; i++)
        {
            arr[i] = new int[n];
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                    arr[i][j] = 1;
                else
                    arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
            }
        return arr[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;
    int result = sol.uniquePaths(m, n);
    cout << "Number of unique paths from top-left to bottom-right: " << result << endl;
    return 0;
}