#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &matrix, int row, int col, char num)
{

    // check if it is safe in row and column
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][col] == num || matrix[row][i] == num)
        {
            return false;
        }
    }

    // check if it is safe in 3x3 grid

    int start_row = row - row % 3;
    int start_col = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (matrix[start_row + i][start_col + i] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
            {
                for (char num = '1'; num <= '9'; num++)
                {
                    if (isSafe(board, row, col, num))
                    {
                        board[row][col] = num;

                        if (sudokuSolver(board))
                        {
                            return true;
                        }

                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void sudoku(vector<vector<char>> &board)
{
    if (sudokuSolver(board))
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists." << endl;
    }
}

int main()
{

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    sudoku(board);
}