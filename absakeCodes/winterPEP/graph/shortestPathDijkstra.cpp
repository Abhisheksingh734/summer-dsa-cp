#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> shortestPath(int source, vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size() - 1;

    vector<ll> dist(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);

    // set<pair<ll, int>> st;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, source});
    // st.insert({0, source});
    dist[source] = 0;

    while (!pq.empty())
    {

        auto node = pq.top();
        pq.pop();

        int node_v = node.second;
        ll node_wt = node.first;

        if (vis[node_v])
            continue;

        vis[node_v] = true;

        for (auto child : adj[node_v])
        {
            int child_v = child.first;
            ll child_wt = child.second;

            if (dist[node_v] + child_wt < dist[child_v])
            {
                dist[child_v] = dist[node_v] + child_wt;
                pq.push({dist[child_v], child_v});
            }
        }
    }

    return dist;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
    }

    vector<ll> path = shortestPath(1, adj);

    for (int i = 1; i <= n; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}