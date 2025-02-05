#include <bits/stdc++.h>
using namespace std;

void nthStairClimb(int N, int k)
{
    vector<int> dp(N+1, 0);

    dp[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                dp[i] += dp[i - j];
        }
    }

    cout << dp[N - 1];
}

int main()
{
    nthStairClimb(5, 2);
}