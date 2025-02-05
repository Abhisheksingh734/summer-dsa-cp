#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int noOfWaysToAttendParty(int n, int dp[])
{

    if (n == 1 || n == 0)
        return 1;

    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = noOfWaysToAttendParty(n - 1, dp) + ((n - 1) * noOfWaysToAttendParty(n - 2, dp));
}

int main()
{
    int n = 5;
    int dp[n + 1];
    memset(dp, -1, n);
    cout << noOfWaysToAttendParty(n, dp);
}