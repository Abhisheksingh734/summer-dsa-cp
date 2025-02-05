#include <bits/stdc++.h>
using namespace std;

bool canPlaceCow(vector<int> arr, int max, int C)
{
    int cow = 1;

    int lastCowPlaced = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {

        if (arr[i] - lastCowPlaced >= max)
        {
            cow++;
            lastCowPlaced = arr[i];
        }
    }

    if (cow >= C)
        return true;
    return false;
}

void absake()
{

    int N, C;
    cin >> N >> C;

    vector<int> stalls(N, 0);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        stalls[i] = num;
    }

    sort(stalls.begin(), stalls.end());
    int start = 1;
    int end = stalls[N - 1] - stalls[0];

    int res = -1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (canPlaceCow(stalls, mid, C))
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << res << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        absake();
    }
}
