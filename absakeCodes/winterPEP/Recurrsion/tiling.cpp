#include <bits/stdc++.h>
using namespace std;

int noOfWaysTiling(int n)
{
    if (n < 4)
        return 1;

    int h = noOfWaysTiling(n - 4);
    int v = noOfWaysTiling(n - 1);

    return h + v;
}

int noOfWaysItr(int n)
{

    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];

        if (i >= 4)
        {
            dp[i] += dp[i - 4];
        }
    }

    return dp[n];
}

int main()
{

    cout << noOfWaysTiling(8) << endl;
    cout << noOfWaysItr(8) << endl;
}
