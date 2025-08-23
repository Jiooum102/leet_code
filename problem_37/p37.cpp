#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isValidNum(bool Check[3][9][10], int row, int col, int box, int x)
    {
        if (Check[0][row][x] == true || Check[1][col][x] == true || Check[2][box][x] == true)
        {
            return false;
        }
        return true;
    }
    void Mark(vector<vector<char>> &board, bool Check[3][9][10], int row, int col, int box, int x)
    {
        if (Check[0][row][x] == false)
        {
            Check[0][row][x] = true;
            Check[1][col][x] = true;
            Check[2][box][x] = true;
            board[row][col] = char(x + '0');
        }
        else
        {
            Check[0][row][x] = false;
            Check[1][col][x] = false;
            Check[2][box][x] = false;
            board[row][col] = char('.');
        }
    }
    bool TraceBack(vector<vector<char>> &board, bool Check[3][9][10], int row, int col)
    {
        int i = row, j = col;
        while (j > 8 || (i < 9 && board[i][j] != '.'))
        {
            if (j > 8)
            {
                j = 0;
                i++;
            }
            else
                j++;
        }
        if (i == 9)
            return true;
        int box = 3 * (int(i / 3)) + j / 3;
        for (int val = 1; val < 10; val++)
        {
            if (isValidNum(Check, i, j, box, val))
            {
                Mark(board, Check, i, j, box, val);
                if (TraceBack(board, Check, i, j))
                    return true;
                Mark(board, Check, i, j, box, val);
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        bool Check[3][9][10] = {false};
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int get = int(board[i][j] - '0');
                    int box = 3 * (int(i / 3)) + j / 3;
                    Check[0][i][get] = true;
                    Check[1][j][get] = true;
                    Check[2][box][get] = true;
                }
            };
        bool dummy = TraceBack(board, Check, 0, 0);
    }
};
int main()
{
    Solution sol;
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter the Sudoku board (9x9 grid, use '.' for empty cells):" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
    sol.solveSudoku(board);
    cout << "Solved Sudoku board:" << endl;
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}