#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> CrtVct(vector<int>& q,int n)
    {
        vector<string> out;
        for(int i=0;i<n;i++)
        {
            string tmp="";
            int j=0;
            while(j<q[i])
            {
                tmp+=".";
                j++;
            }
            tmp+="Q";
            j++;
            while(j<n)
            {
                tmp+=".";
                j++;
            }
            out.push_back(tmp);
        }
        return out;
    }
    int CntL(int row, int col, int n)
    {
        return row+col;
    }
    int CntR(int row, int col, int n)
    {
        return n+row-col-1;
    }
    void Gnr(vector<vector<string>>& res, vector<int>& q, vector<bool>& c, vector<bool>& l, vector<bool>& r, const int& n, int index){
        if(index==n)
        {
            vector<string> board=CrtVct(q,n);
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(c[i]&&l[CntL(index,i,n)]&&r[CntR(index,i,n)])
            {
                int CL=CntL(index,i,n),CR=CntR(index,i,n);
                q[index]=i;
                c[i]=false;
                l[CL]=false;
                r[CR]=false;
                Gnr(res,q,c,l,r,n,index+1);
                c[i]=true;
                l[CL]=true;
                r[CR]=true;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> q(n,0);
        vector<bool> c(n, true);
        vector<bool> l(2 * n, true);
        vector<bool> r(2 * n, true);
        Gnr(res,q,c,l,r,n,0);
        return res;
    }
};
int main()
{
    Solution sol;
    int n;
    cout << "Enter the size of the board (n x n): ";
    cin >> n;
    vector<vector<string>> solutions = sol.solveNQueens(n);
    cout << "All unique solutions: " << endl;
    for (const auto& board : solutions)
    {
        for (const auto& row : board)
        {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}