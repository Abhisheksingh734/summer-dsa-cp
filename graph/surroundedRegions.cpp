#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == (n - 1) || j == 0 || j == (m - 1))
            {
                if (board[i][j] == 'O')
                {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
    }

    int delr[] = {0, 0, -1, 1};
    int delc[] = {-1, 1, 0, 0};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nrow = row + delr[k];
            int ncol = col + delc[k];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                board[i][j] = 'X';
            }
        }
    }
}