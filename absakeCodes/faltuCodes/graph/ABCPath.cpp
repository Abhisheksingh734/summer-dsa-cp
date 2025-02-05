#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;

    vector<vector<char>> matrix(n, vector<char>(e, ' '));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            char c;
            cin >> c;
            matrix[i][j] = c;
        }
    }

    int x, y;
    cin >> x >> y;
}