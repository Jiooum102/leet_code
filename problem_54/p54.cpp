#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int cmin = 0, rmin = 0, cmax = matrix[0].size() - 1, rmax = matrix.size() - 1;
        int xcu = 0, ycur = 0;
        while (cmin <= cmax && rmin <= rmax)
        {
            for (int i = cmin; i <= cmax; ++i)
            {
                result.push_back(matrix[rmin][i]);
            }
            rmin++;
            for (int i = rmin; i <= rmax; ++i)
            {
                result.push_back(matrix[i][cmax]);
            }
            cmax--;
            if (rmin <= rmax)
            {
                for (int i = cmax; i >= cmin; --i)
                {
                    result.push_back(matrix[rmax][i]);
                }
                rmax--;
            }
            if (cmin <= cmax)
            {
                for (int i = rmax; i >= rmin; --i)
                {
                    result.push_back(matrix[i][cmin]);
                }
                cmin++;
            }
        }
        return result;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> matrix;
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;
    matrix.resize(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    vector<int> result = sol.spiralOrder(matrix);
    cout << "Spiral Order: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}