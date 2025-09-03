#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int depth = matrix.size();
        int width = matrix[0].size();
        int left = 0, right = depth * width - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int row = mid / width, col = mid % width;
            if (target == matrix[row][col])
                return true;
            if (target > matrix[row][col])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int target;
    cout << "Enter the target number: ";
    cin >> target;
    if (sol.searchMatrix(matrix, target))
        cout << "Number found!" << endl;
    else
        cout << "Number not found." << endl;
    return 0;
}