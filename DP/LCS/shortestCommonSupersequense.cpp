#include <bits/stdc++.h>
using namespace std;

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

string shortestCommonSupersequence(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    // first we find the longest common subsequnces ------
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
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

    int i = n, j = m;
    string s;

    while (i > 0 && j > 0)
    {

        if (str1[i - 1] == str2[j - 1])
        {
            s.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                s.push_back(str1[i - 1]);
                i--;
            }
            else
            {
                s.push_back(str2[j - 1]);
                j--;
            }
        }
    }

    while (i > 0)
    {
        s.push_back(str1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        s.push_back(str2[j - 1]);
        j--;
    }

    reverse(s.begin(), s.end());
    return s;
}

int main()
{
}