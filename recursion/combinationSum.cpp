#include <bits/stdc++.h>

using namespace std;

void combinationSum(vector<int> &arr, vector<int> &ans, int index, int target, vector<vector<int>> &res)
{
    if (index == arr.size())
    {
        if (target == 0)
        {
            res.push_back(ans);
        }
        return;
    }

    if (arr[index] <= target)
    {
        ans.push_back(arr[index]); // pick the element
        combinationSum(arr, ans, index, target - arr[index], res);
        ans.pop_back(); // drop the element
    }
    combinationSum(arr, ans, index + 1, target, res);
}

int main()
{
    vector<vector<int>> ans;
    vector<int> cand = {2, 1, 3};
    vector<int> ds;
    combinationSum(cand, ds, 0, 7, ans);

    for (auto x : ans)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}