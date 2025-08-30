#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<int> path;
        int depth = grid.size();
        int width = grid[0].size();
        path.push_back(grid[0][0]);
        for (int i = 0; i < depth; i++)
            for (int j = 0; j < width; j++)
            {
                if (i < 1)
                {
                    if (j < 1)
                        continue;
                    path.emplace_back(path[j - 1] + grid[i][j]);
                }
                else
                {
                    if (j < 1)
                        path[j] += grid[i][j];
                    else
                        path[j] = min(path[j], path[j - 1]) + grid[i][j];
                }
            }
        return path.back();
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid;
    int row, col;
    cout << "Enter the number of rows:" << endl;
    cin >> row;
    cout << "Enter the number of columns:" << endl;
    cin >> col;
    grid.resize(row, vector<int>(col));
    cout << "Enter the grid values (space-separated):" << endl;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> grid[i][j];
    int result = sol.minPathSum(grid);
    cout << "Minimum path sum is: " << result << endl;
}