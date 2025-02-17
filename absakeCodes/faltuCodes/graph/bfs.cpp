#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int n;
    vector<vector<int>> adj;

public:
    Graph(int _n) : n(_n), adj(_n + 1) {}

    void addEdge(int x, int y, bool undir = true)
    {
        adj[x].push_back(y);
        if (undir)
            adj[y].push_back(x);
    }

    void printGraph()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << "- ";
            for (int child : adj[i])
            {
                cout << child << " ";
            }
            cout << endl;
        }
    }

    void bfs(int source, vector<int> &vis, vector<int> &level)
    {
        queue<int> q;

        q.push(source);
        vis[source] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (auto child : adj[node])
            {
                if (vis[child])
                    continue;
                vis[child] = 1;
                q.push(child);
                level[child] = level[node] + 1;
            }
        }
    }

    void bfs(int source)
    {
        vector<int> vis(n + 1, 0);
        vector<int> level(n, 0);

        bfs(source, vis, level);
        cout << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << i << " - " << level[i] << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Graph g(n);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        g.addEdge(x, y);
    }
    g.printGraph();
    g.bfs(1);
}

/*

13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11
9 11

 */