#include <bits/stdc++.h>
using namespace std;

//--------------memoisation
int lcs_memo(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (x[n - 1] == y[m - 1])
    {
        dp[n][m] = 1 + lcs_memo(x, y, n - 1, m - 1, dp);
    }
    else
    {
        dp[n][m] = max(lcs_memo(x, y, n, m - 1, dp), lcs_memo(x, y, n - 1, m, dp));
    }

    return dp[n][m];
}

//--------Tabulation
int lcs_tab(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // filling up the table
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {

            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return lcs_memo(text1, text2, n, m, dp);
}