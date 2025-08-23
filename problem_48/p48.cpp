#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int len = matrix.size();
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len / 2; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][len - j - 1];
                matrix[i][len - j - 1] = tmp;
            }
        }
    }
};
int main()
{
    Solution sol;
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    sol.rotate(matrix);
    cout << "Rotated matrix:" << endl;
    for (const auto &row : matrix)
    {
        for (int elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}