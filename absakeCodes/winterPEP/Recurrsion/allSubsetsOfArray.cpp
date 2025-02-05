#include <bits/stdc++.h>
using namespace std;

void allSubsets(vector<int> arr, int i, vector<vector<int>> &res, vector<int> &ans)
{
    if (i >= arr.size())
    {
        res.push_back(ans);
        return;
    }

    ans.push_back(arr[i]);
    allSubsets(arr, i + 1, res, ans);
    ans.pop_back();
    allSubsets(arr, i + 1, res, ans);
}

int main()
{

    vector<vector<int>> res;
    vector<int> ans;
    vector<int> arr = {2, 3, 4};
    vector<bool> vis(arr.size());
    allSubsets(arr, 0, res, ans);

    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }

        cout << endl;
    }
}