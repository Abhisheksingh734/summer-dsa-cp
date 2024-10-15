#include <bits/stdc++.h>

using namespace std;

void subsets(vector<int> &nums, int index, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    int n = nums.size();

    for (int i = index; i < n; i++)
    {
        if (i != index && nums[i] == nums[i - 1])
            continue;

        ds.push_back(nums[i]);
        subsets(nums, i + 1, ds, ans);
        ds.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 2, 2};
    vector<int> ds;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    subsets(arr, 0, ds, ans);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}