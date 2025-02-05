#include <bits/stdc++.h>
using namespace std;

int matrixChain(vector<int> dmn, int i, int j, vector<vector<int>> memo)
{
    if (i == j)
    {
        return 0;
    }

    int minCost = INT_MAX;

    for (int k = i; k < j; k++)
    {

        int cost = matrixChain(dmn, i, k) + matrixChain(dmn, k + 1, j) + dmn[i - 1] * dmn[k] * dmn[j];

        minCost = min(cost, minCost);
    }

    return minCost;
}

int main()
{
    vector<int> arr = {4, 6, 3, 5};
    cout << matrixChain(arr, 1, arr.size() - 1);
}