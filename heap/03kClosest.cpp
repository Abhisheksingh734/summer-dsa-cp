#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

vector<int> absake(int arr[], int size, int x, int k)
{
    priority_queue<pi> maxH;
    vector<int> ans;

    for (int i = 0; i < size; i++)
    {
        int key = abs(arr[i] - x);
        maxH.push({key, arr[i]});

        if (maxH.size() > k)
        {
            maxH.pop();
        }
    }

    while (maxH.size() > 0)
    {
        ans.push_back(maxH.top().second);
        maxH.pop();
    }

    return ans;
}

int main()
{
    int arr[] = {5, 6, 7, 8, 9};
    int size = 5;
    int x = 7;
    int k = 3;

    vector<int> ans = absake(arr, size, x, k);
    for (int i : ans)
    {
        cout << i << " ";
    }
}