#include <bits/stdc++.h>

using namespace std;

// reverse array using recursion

// rev( 2 , 3, 6, 4, 1)
// rev( 3, 6, 4, 1), 2
// rev(6, 4, 1) , 3 , 2

void rev(vector<int> &arr, int s, int e)
{

    if (s == e)
        return;

    swap(arr[s], arr[e]);
    rev(arr, s + 1, e - 1);
}

int main()
{
    vector<int> arr = {2, 3, 6, 4, 1};
    rev(arr, 0, 4);

    for (auto &it : arr)
    {
        cout << it << " ";
    }
}