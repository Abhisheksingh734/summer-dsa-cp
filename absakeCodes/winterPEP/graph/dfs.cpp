#include <bits/stdc++.h>
using namespace std;

class Graph
{

    int V;
    vector<vector<int>> adj;

public:
    Graph(int v) : V(v), adj(v)
    {
    }

    void addEdge(int i, int j, bool undir = true)
    {
        adj[i].push_back(j);
        if (undir)
            adj[j].push_back(i);
    }

    void dfsHelper(int node, vector<bool> &vis)
    {
        vis[node] = true;
        cout << node << " ";
        for (auto nbr : adj[node])
        {
            if (vis[nbr])
                continue;

            dfsHelper(nbr, vis);
        }

        return;
    }
    void dfs(int source)
    {
        vector<bool> vis(V, false);
        dfsHelper(source, vis);
    }
};

int main()
{

    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    // g.printAdjList();
    g.dfs(1);
}