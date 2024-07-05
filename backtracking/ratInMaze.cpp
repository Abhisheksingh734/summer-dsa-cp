#include <bits/stdc++.h>

using namespace std;

struct Choice
{
    char dname;
    int dx, dy;
};

bool isSolved(int x, int y, int n)
{
    return x == n - 1 && y == n - 1;
}

bool isValid(int x, int y, int n, vector<vector<int>> &arr)
{
    return x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1;
}

void solve(int x, int y, int n, vector<vector<int>> &arr, vector<string> &res, string &path, vector<Choice> &choices)
{

    if (isSolved(x, y, n))
    {
        res.push_back(path);
        return;
    }

    for (const auto &choice : choices)
    {
        int newX = x + choice.dx;
        int newY = y + choice.dy;

        if (isValid(newX, newY, n, arr))
        {
            arr[x][y] = 0;

            path.push_back(choice.dname);
            solve(newX, newY, n, arr, res, path, choices);
            arr[x][y] = 1;
            path.pop_back();
        }
    }
}

vector<string> findPath(vector<vector<int>> &arr, int n)
{
    vector<string> res;
    string path = "";
    vector<Choice> choices = {{'U', -1, 0}, {'D', 1, 0}, {'L', 0, -1}, {'R', 0, 1}};

    if (arr[0][0] == 1)
    {
        solve(0, 0, n, arr, res, path, choices);
    }

    return res;
}

int main()
{
    int n = 4;
    vector<vector<int>> arr = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 1, 1, 1}};

    vector<string> paths = findPath(arr, n);

    if (paths.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (const string &path : paths)
        {
            cout << path << endl;
        }
    }

    return 0;
}
