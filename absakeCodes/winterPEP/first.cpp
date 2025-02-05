#include <bits/stdc++.h>
using namespace std;

void findMax(vector<int> arr, int k)
{
    int i = 0;
    int j = 0;

    int sum = 0;
    int maxy = 0;
    while (j < arr.size())
    {

        sum += arr[j];

        if (j - i + 1 > k)
        {
            sum -= arr[i];
            i++;
        }

        if (j - i + 1 == k)
        {
            maxy = max(sum, maxy);
        }

        j++;
    }

    cout << maxy;
}

int main()
{
    vector<int> arr = {6, 2, 3, 4};

    findMax(arr, 3);
}