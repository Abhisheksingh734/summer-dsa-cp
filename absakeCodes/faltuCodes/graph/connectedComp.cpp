#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex, vector<int> graph[], vector<bool> &vis)
{
    vis[vertex] = true;

    for (auto child : graph[vertex])
    {
        if (vis[child])
            continue;

        dfs(child, graph, vis);
    }
}

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

    vector<bool> vis(n + 1, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i, graph, vis);
        }
    }

    cout << cnt << endl;
}