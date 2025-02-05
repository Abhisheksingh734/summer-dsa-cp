#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i++] != s[j--])
        {
            return false;
        }
    }

    return true;
}

int minCutsToPalindrome(string s, int i, int j)
{
    if (i >= j || checkPalindrome(s, i, j))
    {
        return 0;
    }

    int minCuts = INT_MAX;

    for (int k = i; k < j; k++)
    {

        if (checkPalindrome(s, i, k))
        {
            int cuts = 1 + minCutsToPalindrome(s, k + 1, j);

            minCuts = min(cuts, minCuts);
        }
    }

    return minCuts;
}

int main()
{

    cout << minCutsToPalindrome("abcbabc", 0, 6);
    cout << minCutsToPalindrome("aacbabc", 0, 6);
}