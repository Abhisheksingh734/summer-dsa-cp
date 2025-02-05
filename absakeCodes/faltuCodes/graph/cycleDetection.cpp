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

bool detectCycle(int vertex, int parent, vector<int> graph[], vector<bool> &vis)
{
    vis[vertex] = true;

    for (auto child : graph[vertex])
    {
        if (vis[child] && child != parent)
        {
            return true;
        }

        if (vis[child])
            continue;

        if (detectCycle(child, vertex, graph, vis))
        {
            return true;
        }
    }

    return false;
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
    // int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (detectCycle(i, -1, graph, vis))
            {
                cout << "Cycle detected" << endl;

                return 0;
            }
        }
    }

    cout << "No Cycle detected" << endl;

    // cout << cnt << endl;
}