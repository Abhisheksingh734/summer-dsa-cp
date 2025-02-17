#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> parent;

pair<int, int> bfs(int r, int c, vector<vector<char>> &building, vector<vector<int>> &vis)
{

    int n = building.size();
    int m = building[0].size();

    queue<pair<int, int>> q;
    vis[r][c] = 1;
    q.push({r, c});

    int dirX[] = {-1, 1, 0, 0};
    int dirY[] = {0, 0, -1, 1};

    pair<int, int> brow = {-1, -1};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        char dirChar[] = {'U', 'D', 'L', 'R'};

        if (building[row][col] == 'B')
        {
            brow = {row, col};

            break;
        }
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nrow = row + dirX[k];
            int ncol = col + dirY[k];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && building[nrow][ncol] == '.')
            {
                vis[nrow][ncol] = 1;
                parent[nrow][ncol] = {row, col};
                q.push({nrow, ncol});
            }
        }
    }

    return brow;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> building(n, vector<char>(m, ' '));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> building[i][j];
        }
    }
    int noOfRooms = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<char> path;

    parent.resize(n, vector<pair<int, int>>(m, {-1, -1}));

    pair<int, int> start, brow = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (building[i][j] == 'A')
            {

                brow = bfs(i, j, building, vis);
            }
        }
    }

    if (brow.first == -1 && brow.second == -1)
    {
        return -1;
    }
    else
    {

        pair<int, int> temp = parent[brow.first][brow.second];
        // finding the parent
    }
}