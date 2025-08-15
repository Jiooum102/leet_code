#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool Check[3][9][10] = {false};
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int get = int(board[i][j] - '0');
                    int box = 3 * (int(i / 3)) + j / 3;
                    if (Check[0][i][get] == true || Check[1][j][get] == true || Check[2][box][get] == true)
                    {
                        return false;
                    }
                    Check[0][i][get] = true;
                    Check[1][j][get] = true;
                    Check[2][box][get] = true;
                }
            }
        return true;
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
    cout << (sol.isValidSudoku(board) ? "Valid" : "Invalid") << endl;
}