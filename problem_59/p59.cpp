#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int last = n * n;
        vector<vector<int>> result(n, vector<int>(n, 0));
        int xcur = 0, ycur = 0, index = 0, count = 0, times = n - 1;
        int xroad[] = {0, 1, 0, -1};
        int yroad[] = {1, 0, -1, 0};
        for (int i = 1; i <= last; i++)
        {
            result[xcur][ycur] = i;
            xcur += xroad[index];
            ycur += yroad[index];
            count++;
            if (count == times)
            {
                count = 0;
                index++;
                if (index > 3)
                    index = 0;
                if (xcur == times && ycur == 0 && index > 2)
                    times--;
                else if (n - times > 1 && index % 2)
                    times--;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;
    vector<vector<int>> result = sol.generateMatrix(n);
    cout << "Generated " << n << "x" << n << " matrix in spiral order:" << endl;
    for (const auto &row : result)
    {
        for (const auto &val : row)
        {
            cout << val << "\t";
        }
        cout << endl;
    }
    return 0;
}