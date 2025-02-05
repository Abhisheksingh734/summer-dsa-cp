#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void dfs(int vertex, int par, vector<int> graph[], vector<int> &sumOfSubtree, vector<int> &val)
{
    sumOfSubtree[vertex] += val[vertex - 1];
    for (int child : graph[vertex])
    {

        if (child == par)
            continue;

        dfs(child, vertex, graph, sumOfSubtree, val);
        sumOfSubtree[vertex] += sumOfSubtree[child];
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int>> &B)
{

    vector<int> graph[A.size() + 1];
    vector<int> sumOfSubtree(A.size() + 1, 0);
    for (auto edge : B)
    {

        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    dfs(1, 0, graph, sumOfSubtree, A);

    long long maxMul = 0;

    for (int i = 2; i <= A.size(); i++)
    {
        int part1 = sumOfSubtree[i];
        int part2 = sumOfSubtree[1] - part1;

        maxMul = max(maxMul, (part1 * 1LL * part2) % MOD);
    }

    return maxMul;
}