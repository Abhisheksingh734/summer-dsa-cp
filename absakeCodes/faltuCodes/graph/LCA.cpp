#include <bits/stdc++.h>
using namespace std;

void findPath(int src, int par, vector<vector<int>> &adj, vector<int> &parent)
{
    parent[src] = par;
    for (int child : adj[src])
    {
        if (child == par)
            continue;
        findPath(child, src, adj, parent);
    }
}

vector<int> getPath(int v, vector<int> &parent)
{
    vector<int> ans;
    while (v != -1)
    {
        ans.push_back(v);
        v = parent[v]; // Move to the parent
    }
    reverse(ans.begin(), ans.end()); // Ensure path is root -> node
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> parent(n + 1, -1);
    findPath(1, -1, adj, parent);

    vector<int> pathA = getPath(5, parent);
    vector<int> pathB = getPath(2, parent);

    int i = 0;
    while (i < min(pathA.size(), pathB.size()) && pathA[i] == pathB[i])
    {
        i++;
    }

    cout << pathA[i - 1] << endl;
    return 0;
}
