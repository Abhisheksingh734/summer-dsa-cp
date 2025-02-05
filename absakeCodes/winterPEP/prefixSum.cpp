#include <bits/stdc++.h>
using namespace std;

int findSum()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int m;
    cin >> m;
    while (m--)
    {
        int i, j, k;
        cin >> i >> j >> k;

        arr[i] += k;
        arr[j + 1] -= k;
    }

    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }

    for (auto x : arr)
    {
        cout << x << " ";
    }
}

int main()
{
    findSum();
}