#include <bits/stdc++.h>
using namespace std;

int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// Check if the cell is valid for traversal
bool isValid(int x, int y, int n, const vector<vector<char>> &grid)
{
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 'M';
}

int findMinWater(int n, const vector<vector<char>> &grid, pair<int, int> start, pair<int, int> end)
{
    vector<vector<int>> waterUsed(n, vector<int>(n, INT_MAX));
    queue<pair<int, int>> cellsQueue;

    cellsQueue.push(start);
    waterUsed[start.first][start.second] = 0;

    while (!cellsQueue.empty())
    {
        pair<int, int> current = cellsQueue.front();
        cellsQueue.pop();

        int x = current.first;
        int y = current.second;

        for (int d = 0; d < 4; d++)
        {
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];

            if (isValid(nx, ny, n, grid))
            {
                int cost = (grid[x][y] == 'T' && grid[nx][ny] == 'T') ? 0 : 1;
                if (waterUsed[x][y] + cost < waterUsed[nx][ny])
                {
                    waterUsed[nx][ny] = waterUsed[x][y] + cost;
                    cellsQueue.push({nx, ny});
                }
            }
        }
    }

    return waterUsed[end.first][end.second] == INT_MAX ? -1 : waterUsed[end.first][end.second];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                start = {i, j};
            if (grid[i][j] == 'E')
                end = {i, j};
        }
    }

    int result = findMinWater(n, grid, start, end);
    if (result != -1)
        cout << result;
    else
        cout << "End point not reachable." << endl;

    return 0;
}
