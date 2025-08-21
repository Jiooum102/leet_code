#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int CntL(int row, int col, int n)
    {
        return row + col;
    }
    int CntR(int row, int col, int n)
    {
        return n + row - col - 1;
    }
    void Gnr(int &res, vector<bool> &c, vector<bool> &l, vector<bool> &r, const int &n, int index)
    {
        if (index == n)
        {
            res++;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (c[i] && l[CntL(index, i, n)] && r[CntR(index, i, n)])
            {
                int CL = CntL(index, i, n), CR = CntR(index, i, n);
                c[i] = false;
                l[CL] = false;
                r[CR] = false;
                Gnr(res, c, l, r, n, index + 1);
                c[i] = true;
                l[CL] = true;
                r[CR] = true;
            }
        }
    }
    int totalNQueens(int n)
    {
        int res = 0;
        vector<bool> c(n, true);
        vector<bool> l(2 * n, true);
        vector<bool> r(2 * n, true);
        Gnr(res, c, l, r, n, 0);
        return res;
    }
};
int main()
{
    Solution sol;
    int n;
    cout << "Enter the size of the chessboard (n): ";
    cin >> n;
    int result = sol.totalNQueens(n);
    cout << "Total solutions for " << n << " queens: " << result << endl;
    return 0;
}