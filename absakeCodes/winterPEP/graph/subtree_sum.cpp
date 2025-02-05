#include <bits/stdc++.h>
using namespace std;

void dfs(int src, int par, vector<vector<int>> &graph, vector<int> &subtree_sum)
{

    subtree_sum[src] += src;
    for (auto child : graph[src])
    {
        if (child == par)
            continue;

        dfs(child, src, graph, subtree_sum);

        subtree_sum[src] += subtree_sum[child];
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    vector<int> subtree_sum(n + 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;

        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1, 0, graph, subtree_sum);

    for (int i = 1; i < subtree_sum.size(); i++)
    {
        cout << "subtree sum of " << i << " node -> " << subtree_sum[i] << endl;
    }

    return 0;
}
