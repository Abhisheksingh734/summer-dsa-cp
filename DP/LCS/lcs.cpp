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

int longestCommonSubString(string nums1, string nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    // Create a new dp matrix
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            // answer for "ab" "ab" would be answer at "a""a" + 1
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
            // we need to start a new substring because substrings are continous
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

void print_lcs(string x, string y, int n, int m)
{
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));

    // filling up the table
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {

            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + x[i - 1];
            }
            else
            {
                dp[i][j] = (dp[i][j - 1].length() > dp[i - 1][j].length()) ? dp[i][j - 1] : dp[i - 1][j];
            }
        }
    }

    cout << dp[n][m] << endl;
}

int main()
{

    print_lcs("acabc", "abcds", 5, 5);
}