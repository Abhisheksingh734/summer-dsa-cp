#include <bits/stdc++.h>
using namespace std;

void nthStairClimb(int N, int k)
{
    vector<int> dp(N + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    ///  -------- dp part --------
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         if (i - j >= 0)
    //             dp[i] += dp[i - j];
    //     }
    // }

    int i = 0;
    int j = 2;

    int sum = 0;

    while (j <= N)
    {

        // sum += dp[i-1];

        if (j - i <= k)
        {
            dp[j] = 2 * dp[j - 1];
        }
        else
        {
            dp[j] = (2 * dp[j - 1]) - dp[i];
            i++;
        }

        j++;
    }

    cout << dp[N];
}

int main()
{
    nthStairClimb(5, 2);
}