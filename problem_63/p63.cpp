#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<int> path;
        int depth = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        path.push_back(min(1, 1 - obstacleGrid[0][0]));
        for (int i = 0; i < depth; i++)
            for (int j = 0; j < width; j++)
            {
                if (i < 1)
                {
                    if (j < 1)
                        continue;
                    path.push_back(min(path[j - 1], 1 - obstacleGrid[i][j]));
                }
                else
                {
                    if (obstacleGrid[i][j] > 0)
                    {
                        path[j] = 0;
                        continue;
                    }
                    if (j > 0)
                        path[j] += path[j - 1];
                }
            }
        return path.back();
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> obstacleGrid;
    int row, col;
    cout << "Enter the number of rows:" << endl;
    cin >> row;
    cout << "Enter the number of columns:" << endl;
    cin >> col;
    obstacleGrid.resize(row, vector<int>(col));
    cout << "Enter the obstacle grid (0 for free cell, 1 for obstacle, every element is divided by space):" << endl;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> obstacleGrid[i][j];
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << result << endl;
}