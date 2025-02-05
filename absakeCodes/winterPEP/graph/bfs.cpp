#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int i, int j, bool undir = true)
    {
        adj[i].push_back(j);
        if (undir)
            adj[j].push_back(i);
    }

    void printAdjList()
    {

        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            for (auto x : adj[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void bfs(int source)
    {

        queue<int> q;

        vector<bool> vis(V, false);

        q.push(source);
        vis[source] = true;

        while (!q.empty())
        {
            // do some work for every nore
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (auto nbr : adj[node])
            {
                if (vis[nbr])
                    continue;

                q.push(nbr);
                vis[nbr] = true;
            }
        }
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

    g.printAdjList();
    g.bfs(1);

    return 0;
}