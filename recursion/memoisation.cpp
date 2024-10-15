#include <bits/stdc++.h>

using namespace std;
int memoization(int weight[], int val[], int W, int n, int dp[][5])
{

    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (dp[W][n] != -1)
    {
        return dp[W][n];
    }

    if (weight[n - 1] <= W)
    {
        return dp[W][n] = max(val[n - 1] + memoization(weight, val, W - weight[n - 1], n - 1, dp), memoization(weight, val, W, n - 1, dp));
    }
    else
    {
        return dp[W][n] = memoization(weight, val, W, n - 1, dp);
    }
}

int main()
{
    int w[] = {1, 3, 4, 5};
    int v[] = {1, 4, 5, 7};
    int W = 7;
    int n = 4;

    int dp[8][5];

    memset(dp, -1, sizeof(dp));

    cout << memoization(w, v, W, n, dp);
}

int tragetSum(vector<int>)