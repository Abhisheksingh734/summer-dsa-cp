#include <bits/stdc++.h>

using namespace std;

bool canWePlace(vector<int> arr, int dist, int cows)
{
    int cntCows = 1;
    int last = arr[0];

    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i] - last >= dist)
        {
            cntCows++;
            last = arr[i];
        }
        if (cntCows == cows)
        {
            return true;
        }
    }

    return false;
}

int cows(vector<int> arr, int cows)
{
    int low = 0;
    int high = arr[arr.size() - 1] - arr[0];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canWePlace(arr, mid, cows))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high;
}

// bool canWeAssign(vector<int> arr, int mid, int m)
// {
//     int st = 1;
//     int pages = 0;

//     for (int i = 0; i < arr.size(); i++)
//     {

//         if (pages + arr[i] <= mid)
//         {
//             pages += arr[i];
//         }
//         else
//         {
//             st++;
//             pages = arr[i];
//         }

//         if (st > m)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int assign(vector<int> arr, int m)
// {
//     int mx = -99;
//     int sum = 0;
//     for (auto i : arr)
//     {
//         sum += i;
//         mx = max(mx, i);
//     }

//     int start = mx;
//     int end = sum;

//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;

//         if (canWeAssign(arr, mid, m))
//         {
//             end = mid - 1;
//         }
//         else
//         {
//             start = mid + 1;
//         }
//     }

//     return start;
// }

void prefixMul(vector<int> &nums)
{
    vector<int> preMul;

    preMul[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        preMul[i] = preMul[i - 1] * nums[i];
    }
    for (auto x : preMul)
    {
        cout << x << " ";
    }
}

int partition(vector<int> arr, int start, int end, int pivot)
{

    int i = 0, j = 0;
    while (j <= end)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[j++], arr[i++]);
        }
        else
        {
            j++;
        }
    }
}

// only be applied when array size is too big and range is significantly small.

void countSort(vector<int> arr)
{
    int min = *min_element(arr.begin(), arr.end());
    int max = *max_element(arr.begin(), arr.end());

    int range = max - min + 1;

    vector<int> rng(range);

    // converting range  array in freq array of main array
    for (int i = 0; i < range; i++)
    {
        int idx = arr[i] - min;
        rng[idx] += 1;
    }

    // convert this into prefix array
    int sum = rng[0];

    for (int i = 1; i < range; i++)
    {
        rng[i] += sum;
        sum += rng[i];
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4};

    prefixMul(arr);
}