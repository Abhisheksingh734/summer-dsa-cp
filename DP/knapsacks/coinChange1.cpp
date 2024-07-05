/**
 * Return the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins,
 *  return -1.
 */

#include <bits/stdc++.h>

using namespace std;

int change(int amt, int coins[], int n)
{
    int t[n + 2][amt + 2];

    // initialisation --> base condt.

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amt; j++)
        {
            if (i == 0)
            {
                t[i][j] = INT_MAX - 1;
            }
            if (j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= amt; j++)
        {

            if (coins[i - 1] <= j)
            {
                t[i][j] = min(t[i][j - coins[i - 1]] + 1, t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][amt] == INT_MAX - 1 ? -1 : t[n][amt];
}

int main()
{

    int n = 1, sum = 3;

    int arr[] = {2};

    int ans = change(sum, arr, n);
    cout << ans;
}