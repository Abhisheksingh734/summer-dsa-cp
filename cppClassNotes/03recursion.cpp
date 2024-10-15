#include <bits/stdc++.h>

using namespace std;

void printInc(int n)
{
    if (n == 0)
        return;

    printInc(n - 1);
    cout << n << " ";
}

void printDec(int n)
{
    // base

    if (n == 0)
        return;

    cout << n << " ";
    printDec(n - 1);
}

void printIncDec(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    printIncDec(n - 1);
    cout << n << " ";
}

int sumOfN(int n)
{
    if (n == 0)
        return 0;

    return n + sumOfN(n - 1);
}

int productOfN(int n)
{
    if (n == 1)
        return 1;

    return n * productOfN(n - 1);
}

int minArr(int arr[], int idx)
{
    if (idx == 1)
        return arr[0];

    return min(arr[0], minArr(arr + 1, idx - 1));
}

int maxArr(int arr[], int idx)
{
    if (idx == 1)
        return arr[0];

    return max(arr[0], maxArr(arr + 1, idx - 1));
}

int contain(vector<int> arr, int idx, int target)
{

    if (idx == 0)
    {
        return false;
    }

    if (arr[idx - 1] == target)
    {
        return true;
    }
    else
    {
        return contain(arr, idx - 1, target);
    }
}

vector<int> allIdx(vector<int> arr, int idx, int target)
{
    if (idx == 0)
    {
        return vector<int>();
    }

    vector<int> ans = allIdx(arr, idx - 1, target);

    if (arr[idx - 1] == target)
    {
        ans.push_back(idx - 1);
    }
    return ans;
}

int climbStair(int n, string ans)
{
    if (n == 0)
    {
        cout << ans << " ";
        return 1;
    }
    if (n < 0)
        return 0;

    int j1 = climbStair(n - 1, ans + "j1");
    int j2 = climbStair(n - 2, ans + "j2");
    int j3 = climbStair(n - 3, ans + "j3");

    return j1 + j2 + j3;
}

int single_coin_combination(vector<int> &arr, int curr, int tar)
{

    if (tar == 0)
        return 1;

    if (curr == 0 || tar < 0)
        return 0;

    int without = single_coin_combination(arr, curr - 1, tar);

    int with = single_coin_combination(arr, curr, tar - arr[curr - 1]);

    return without + with;
}

int single_coin_comb(vector<int> arr, int curr, int tar)
{
    if (tar == 0)
        return 1;

    int ans = 0;
    for (int i = curr; i < arr.size(); i++)
    {
        if (arr[i] <= tar)
        {
            ans += single_coin_comb(arr, curr + 1, tar - arr[i]);
        }
    }

    return ans;
}

int floddFill(vector<vector<int>> &maze, int r, int c, vector<vector<bool>> &vis, vector<vector<int>> &direction)
{

    if (r == maze.size() - 1 && c == maze[0].size() - 1)
    {
        return 1;
    }

    int ans = 0;
    vis[r][c] = true;

    for (vector<int> dir : direction)
    {
        int nr = r + dir[0],
            nc = dir[1];

        if (nr >= 0 && nc >= 0 && nr < maze.size() && nc < maze[0].size() && maze[nr][nc] != 1 && vis[nr][nc] == false)
        {
            ans += floddFill(maze, nr, nc, vis, direction);
        }
    }

    vis[r][c] = false;
    return ans;
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
}

void sudoku(vector<vector<char>> &board)
{
    sudokuSolver(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int tower_of_hanoi(string srs, string dest, string helper, int n)
{

    if (n == 1)
    {
        cout << "Move disk 1 from " << srs << " to " << dest << endl;
        return 1;
    }

    int ans = 0;
    ans += tower_of_hanoi(srs, helper, dest, n - 1);
    cout << "Move " << "th disk from " << srs << "to " << helper << endl;
    ans += 1;
    ans += tower_of_hanoi(helper, dest, srs, n - 1);

    return ans;
}

// void combinatinos(string in, string op, vector<string> &res)
// {

//     if (op.size() == 0)
//     {
//         res.push_back(in);
//         return;
//     }

//     char val = op.front();
//     strinPerm(in + val, op.substr(1, op.size() - 1), res);

//     strinPerm(in, op.substr(1, op.size() - 1), res);
// }

void permutation(string str, vector<int> &visited, vector<char> &psf, vector<string> &ans)
{

    if (psf.size() == str.size())
    {
        string res(psf.begin(), psf.end());
        ans.push_back(res);
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            psf.push_back(str[i]);
            permutation(str, visited, psf, ans);
            psf.pop_back();
            visited[i] = 0;
        }
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

// int main()
// {
//     // printInc(5);
//     // cout << endl;
//     // printDec(5);
//     // cout << endl;
//     // printIncDec(5);
//     // cout << endl;
//     // cout << sumOfN(5) << endl;

//     // cout << productOfN(5) << endl;
//     // int arr[] = {3, 5, 2, 1, 7};
//     // cout << minArr(arr, 5) << endl;
//     // cout << maxArr(arr, 5) << endl;

//     // contain(arr1, 6, 2) ? cout << "contain" : cout << "not contain";

//     // vector<int> res1 = allIdx(arr1, 6, 7);

//     // for (auto i : res1)
//     // {
//     //     cout << i << " ";
//     // }

//     // cout << climbStair(5, "");

//     vector<int> arr1 = {1, 2, 3};

//     cout << single_coin_combination(arr1, arr1.size(), 4);
// }