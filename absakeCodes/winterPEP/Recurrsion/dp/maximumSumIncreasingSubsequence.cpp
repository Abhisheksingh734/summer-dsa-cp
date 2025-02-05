#include <bits/stdc++.h>
using namespace std;

int maximumSumIncreasingSubsequence(vector<int> arr, int n)
{
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    int maxy = 0;
    for (auto x : dp)
    {
        maxy = max(x, maxy);
    }

    return maxy;
}

int main()
{
    vector<int> arr = {2, 5, 1, 4, 7};
    cout << maximumSumIncreasingSubsequence(arr, 5);
}
