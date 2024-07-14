#include <bits/stdc++.h>
using namespace std;

void df(int node, vector<int> adj[], int vis[], vector<int> &ls)
{
    vis[node] = 1;

    ls.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            df(it, adj, vis, ls);
        }
    }
}

void bfs(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    queue<int> q;

    q.push(node);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

int main()
{

    int n, m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}
