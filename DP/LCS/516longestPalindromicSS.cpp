#include <bits/stdc++.h>
using namespace std;

#define vvs vector<vector<string>>
#define vvi vector<vector<int>>

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    string p = s;
    reverse(p.begin(), p.end());
    vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (p[i - 1] == s[j - 1])
            {
                t[i][j] = t[i - 1][j - 1] + 1;
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    return t[n][n];
}