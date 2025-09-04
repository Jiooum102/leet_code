#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int depth = matrix.size();
        int width = matrix[0].size();
        bool *zeroInRow = new bool[depth];
        bool *zeroInCol = new bool[width];
        for (int i = 0; i < depth; i++)
        {
            zeroInRow[i] = false;
            for (int j = 0; j < width; j++)
            {
                if (i < 1)
                    zeroInCol[j] = false;
                if (matrix[i][j] == 0)
                {
                    zeroInCol[j] = true;
                    zeroInRow[i] = true;
                }
            }
        }
        for (int i = 0; i < depth; i++)
            for (int j = 0; j < width; j++)
            {
                if (zeroInCol[j] || zeroInRow[i])
                {
                    matrix[i][j] = 0;
                }
            }
    }
};

int main()
{
    Solution sol;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    sol.setZeroes(matrix);
    cout << "Modified matrix:\n";
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}