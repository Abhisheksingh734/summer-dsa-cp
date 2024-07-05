#include <bits/stdc++.h>

using namespace std;

int absake(int arr[], int size, int k)
{

    priority_queue<int, vector<int>, greater<int>> minH;

    for (int i = 0; i < size; i++)
    {
        minH.push(arr[i]);

        if (minH.size() > k)
        {
            minH.pop();
        }
    }

    return minH.top();
}

int main()
{
    int arr[] = {7, 10, 9, 3, 20, 15};
    int size = 6;
    int k = 3;

    cout << absake(arr, size, k) << endl;
}