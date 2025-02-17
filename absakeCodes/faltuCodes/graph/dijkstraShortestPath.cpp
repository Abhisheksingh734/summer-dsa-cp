#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> dijkstra(int source, int destination, vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size() - 1;
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<int> parent(n + 1, -1);

    set<pair<ll, int>> st;
    dist[source] = 0;

    st.insert({0, source});

    while (!st.empty())
    {

        auto node = *st.begin();

        int node_v = node.second;
        ll node_wt = node.first;

        st.erase(st.begin());

        for (auto child : adj[node_v])
        {

            int child_v = child.first;
            ll child_wt = child.second;

            if (dist[node_v] + child_wt < dist[child_v])
            {
                parent[child_v] = node_v;
                st.erase({dist[child_v], child_v});
                dist[child_v] = dist[node_v] + child_wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }

    if (parent[destination] == -1)
    {
        return {};
    }

    vector<int> path;

    for (int i = destination; i != -1; i = parent[i])
    {
        path.push_back(i);
    }

    reverse(path.begin(), path.end());

    return path;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> path = dijkstra(1, n, adj);

    if (path.empty())
    {
        cout << -1 << endl;
        return 0;
    }

    for (auto x : path)
    {
        cout << x << " ";
    }
}