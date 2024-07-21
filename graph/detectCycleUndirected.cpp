#include <bits/stdc++.h>
using namespace std;

// using bfs
bool check(int src, vector<int> adj[], vector<int> &vis)
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjEle : adj[node])
        {
            if (!vis[adjEle])
            {
                q.push({adjEle, node});
                vis[adjEle] = 1;
            }
            else if (adjEle != parent)
            {
                return true;
            }
        }
    }

    return false;
}

// function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);

    // can be connected components sp loop through them
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (check(i, adj, vis))
                return true;
        }
    }

    return false;
}