#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int n;
    vector<vector<int>> adj;
    vector<int> eulerPath;

public:
    Graph(int _n)
    {
        this->n = _n;
        adj.resize(n);
    }

    void addEdge(int i, int j, bool undir)
    {
        adj[i].push_back(j);

        if (undir)
        {
            adj[j].push_back(i);
        }
    }

    void dfsHelper(int src, int par, vector<bool> &vis)
    {
        eulerPath.push_back(src);
        vis[src] = true;

        for (auto child : adj[src])
        {
            if (child == par || vis[child])
            {
                continue;
            }

            dfsHelper(child, src, vis);
        }
        eulerPath.push_back(src);
    }

    void dfs(int src)
    {
        vector<bool> vis(n, 0);
        dfsHelper(src, -1, vis);
    }
};

int main()
{
}