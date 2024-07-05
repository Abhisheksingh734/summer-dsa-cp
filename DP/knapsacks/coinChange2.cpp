/**
 * Return the number of combinations that make up that amount.
 * If that amount of money cannot be made up by any combination
 * of the coins, return 0.
 */

#include <bits/stdc++.h>

using namespace std;

int change(int amt, int coins[], int n)
{
    int t[n + 2][amt + 2];

    // initialisation --> base condt.
    int mod = 1e9 + 7;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amt; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= amt; j++)
        {

            if (coins[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - coins[i - 1]] + t[i - 1][j]) % mod;
            }
            else
            {
                t[i][j] = (t[i - 1][j]) % mod;
            }
        }
    }

    return t[n][amt];
}

int main()
{

    int n = 6, sum = 10;

    int arr[] = {5, 2, 3, 10, 6, 8};

    int ans = change(sum, arr, n);
    cout << ans;
}