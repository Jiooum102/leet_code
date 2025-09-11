#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int depth = mat.size();
        int width = mat[0].size();
        vector<int> out;
        if (depth * width < 1)
            return out;
        int row = 0, col = 0;
        while (out.size() < depth * width)
        {
            out.push_back(mat[row][col]);
            if ((row + col) % 2 < 1)
            {
                if (width - col < 2)
                    row++;
                else if (row < 1)
                    col++;
                else
                {
                    row--;
                    col++;
                }
            }
            else
            {
                if (depth - row < 2)
                    col++;
                else if (col < 1)
                    row++;
                else
                {
                    col--;
                    row++;
                }
            }
        }
        return out;
    }
};

int main()
{
    Solution sol;
    int row, col;
    cout << "Enter the number of rows:" << endl;
    cin >> row;
    cout << "Enter the number of columns:" << endl;
    cin >> col;
    vector<vector<int>> mat(row, vector<int>(col));
    cout << "Enter the matrix values (space-separated):" << endl;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> mat[i][j];
    vector<int> result = sol.findDiagonalOrder(mat);
    cout << "Diagonal order is: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;
}