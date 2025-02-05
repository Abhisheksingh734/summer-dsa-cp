#include <bits/stdc++.h>
using namespace std;

int targetSum(vector<int> arr, int k)
{

    int n = arr.size();
    vector<int> dp(k + 1, 0);

    dp[0] = 1;

    for (int num : arr)
    {
        for (int j = num; j <= k; j++)
        {
            dp[j] += dp[j - num];
        }
    }

    return dp[k];
}

bool canSumOptimized(vector<int> &nums, int target, vector<int> &memo)
{
    if (target > 0)
        return false;

    if (target == 0)
        return true;

    if (memo[target] != -1)
        return memo[target];

    bool canForm = false;

    for (auto num : nums)
    {
        if (canSumOptimized(nums, target - num, memo))
        {
            canForm = true;
            break;
        }
    }

    memo[target] = canForm;
    return canForm;
}

bool canSumOptmiized(vector<int> &nums, int target)
{
    vector<int> memo(target + 1);

    return canSumOptimized(nums, target, memo);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    cout << targetSum(arr, 4);
}