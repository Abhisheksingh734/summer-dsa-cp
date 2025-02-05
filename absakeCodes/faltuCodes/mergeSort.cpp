#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int i = s;
    int mid = (s + e) / 2;

    int j = mid + 1;

    vector<int> temp;
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while (j <= e)
    {
        temp.push_back(arr[j++]);
    }

    int k = 0;
    for (int idx = s; idx <= e; idx++)
    {
        arr[idx] = temp[k++];
    }
}

void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{

    vector<int> arr = {0, 4, 2, 9, 5, 3, 8, 1};

    mergeSort(arr, 0, arr.size() - 1);

    for (auto x : arr)
    {
        cout << x << " ";
    }
}