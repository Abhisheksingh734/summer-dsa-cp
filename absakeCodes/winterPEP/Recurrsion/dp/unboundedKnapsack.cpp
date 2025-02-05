#include <bits/stdc++.h>
using namespace std;

int maxProfitPossible(vector<int> weights, vector<int> profits, int capacity)
{

    if (capacity == 0)
        return 0;

    int maxProfit = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (weights[i] > capacity)
        {
            continue;
        }

        int ans = maxProfitPossible(weights, profits, capacity - weights[i]);
        if (ans == -1)
            continue;
        ans += profits[i];

        maxProfit = max(ans, maxProfit);
    }

    return maxProfit;
}

int maxProfitPossible(vector<int> &weights, vector<int> &profits, int capacity, int idx)
{
    if (capacity == 0 || idx == weights.size())
    {
        return 0;
    }

    // exclude

    int exc = maxProfitPossible(weights, profits, capacity, idx + 1);
    // include

    int inc = 0;
    if (capacity >= weights[idx])
    {
        inc = profits[idx] + maxProfitPossible(weights, profits, capacity - weights[idx], idx + 1);
    }

    int mxy = max(inc, exc);
    return mxy;
}

int maxPossibleProfitItr(vector<int> weights, vector<int> profit, int capacity)
{
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {

            if (j >= weights[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + profit[i - 1]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    return dp[n][capacity];
}

int main()
{
    vector<int> weights = {1, 3, 4};
    vector<int> profits = {5, 10, 4};

    int capacity = 2;

    // cout << maxProfitPossible(weights, profits, capacity, 0);
    cout << maxPossibleProfitItr(weights, profits, capacity);
}