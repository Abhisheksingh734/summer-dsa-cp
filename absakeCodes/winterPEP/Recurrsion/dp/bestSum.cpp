#include <bits/stdc++.h>
using namespace std;

// find the longest nums that sum up to target using array nums
int bestSum(vector<int> &arr, int target)
{
    if (target < 0)
    {
        return -1;
    }

    if (target == 0)
    {
        return 0;
    }

    int maxy = -1;
    for (auto num : arr)
    {

        int ans = bestSum(arr, target - num);
        if (ans != -1)
        {
            maxy = max(maxy, ans + 1);
        }
    }

    return maxy;
}

int bestSum(vector<int> &arr, int target, vector<int> memo)
{
    if (target < 0)
    {
        return -1;
    }

    if (target == 0)
    {
        return 0;
    }

    if (memo[target] != -1)
        return memo[target];
    int maxy = -1;
    for (auto num : arr)
    {

        int ans = bestSum(arr, target - num);
        if (ans != -1)
        {
            maxy = max(maxy, ans + 1);
        }
    }

    return memo[target] = maxy;
}

int bestSumItr(vector<int> arr, int target)
{
    vector<int> dp(target + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= target; i++)
    {

        for (int num : arr)
        {

            if (i - num >= 0 && dp[i - num] != -1)
            {
                dp[i] = max(dp[i], dp[i - num] + 1);
            }
        }
    }

    return dp[target];
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int target = 4;
    vector<int> memo(target + 1);
    cout << bestSum(nums, target) << endl;
    cout << bestSumItr(nums, target) << endl;
}