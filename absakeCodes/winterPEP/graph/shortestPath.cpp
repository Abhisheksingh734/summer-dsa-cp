#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int n;
    vector<vector<int>> adj;

public:
    Graph(int _n) : n(_n), adj(_n) {}

    void addEdge(int i, int j, bool undir = true)
    {
        adj[i].push_back(j);
        if (undir)
            adj[j].push_back(i);
    }

    void printAdjList()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "->";
            for (auto child : adj[i])
            {
                cout << child << " ";
            }
            cout << endl;
        }
    }

    void shortestPath(int source, int dest = -1)
    {

        queue<int> q;
        vector<int> vis(n, 0);

        vector<int> parent(n, -1);
        vector<int> dist(n, 0);

        parent[source] = source;

        vis[source] = 1;
        q.push(source);

        while (!q.empty())
        {

            int node = q.front();
            q.pop();

            for (auto nbr : adj[node])
            {
                if (!vis[nbr])
                {
                    // update the parent and distance
                    parent[nbr] = node;
                    dist[nbr] = dist[node] + 1;

                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }

        // print the shortest distance to ith node

        for (int i = 0; i < dist.size(); i++)
        {
            cout << "Shortest dist to " << i << " is " << dist[i] << endl;
        }

        // print the path from source to dest
        if (dest != -1)
        {
            int temp = dest;
            while (temp != source)
            {
                cout << temp << " -- ";
                temp = parent[temp];
            }
            cout << source << endl;
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
    g.shortestPath(1, 6);
}