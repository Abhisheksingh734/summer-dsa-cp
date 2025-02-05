#include <bits/stdc++.h>
using namespace std;

int longestCommonSub(string str1, string str2, int m, int n)
{
    if (n == 0 || m == 0)
        return 0;

    if (str1[m - 1] == str2[n - 1])
    {
        return longestCommonSub(str1, str2, m - 1, n - 1) + 1;
    }
    else
    {
        return max(longestCommonSub(str1, str2, m - 1, n), longestCommonSub(str1, str2, m, n - 1));
    }
}

int longesteCommonSubMemo(string str1, string str2, int m, int n, vector<vector<int>> &memo)
{

    if (n == 0 || m == 0)   
        return 0;

    if (memo[m][n] != -1)
        return memo[m][n];

    if (str1[m - 1] == str2[n - 1])
    {
        memo[m][n] = longesteCommonSubMemo(str1, str2, m - 1, n - 1, memo) + 1;
    }
    else
    {
        memo[m][n] = max(longesteCommonSubMemo(str1, str2, m - 1, n, memo), longesteCommonSubMemo(str1, str2, m, n - 1, memo));
    }

    return memo[m][n];
}

int longestCommonSubItr(string str1, string str2, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main()
{
    int m = 6;
    int n = 6;
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    cout << longestCommonSub("paport", "pastpa", m, n) << endl;
    cout << longesteCommonSubMemo("paport", "pastpa", m, n, memo) << endl;
    cout << longestCommonSubItr("paport", "pastpa", m, n);
}