#include <bits/stdc++.h>
using namespace std;
// const int N = 1e3 + 10;
// const int INF = 1e9 + 7;

// 7 10
// 1 3 7
// 1 2 2
// 3 6 3
// 6 2 8
// 6 5 1
// 7 6 3
// 4 7 4
// 2 4 4
// 5 2 3
// 5 4 1

vector<int> dijktsra(int src, vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    set<pair<int, int>> st;
    vector<int> dist(n + 1, INT_MAX);

    st.insert({0, src});
    dist[src] = 0;

    while (!st.empty())
    {
        auto node = *st.begin();

        int node_v = node.second;
        int node_wt = node.first;

        st.erase(st.begin());

        for (auto child : adj[node_v])
        {
            int child_v = child.first;
            int child_wt = child.second;

            if (dist[node_v] + child_wt < dist[child_v])
            {
                dist[child_v] = dist[node_v] + child_wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }

    return dist;
}

int main()
{
    int n, edges;
    cin >> n >> edges;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < edges; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            cout << x.first << " " << x.second << "\n";
        }
    }

    vector<int> dist = dijktsra(1, adj);

    for (auto x : dist)
    {
        cout << x << " ";
    }
}
