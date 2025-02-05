#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, e;
    cin >> n >> e;

    vector<int> graph[n + 1];

    for (int i = 0; i < e; i++)
    {

        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i < n; i++)
    {
        cout << i << "->";
        for (auto y : graph[i])
        {
            cout << y << " ";
        }

        cout << endl;
    }
}