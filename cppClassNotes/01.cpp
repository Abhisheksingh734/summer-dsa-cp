#include <bits/stdc++.h>

using namespace std;

int bs(vector<int> arr, int target, bool firstOcc)
{

    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (target > arr[mid])
        {
            s = mid + 1;
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            if (firstOcc)
            {
                e = mid - 1;
            }
            else
            {

                s = mid + 1;
            }
        }
    }

    return ans;
}

// void update(int &num)
// {
//     num++;
// }

// void swap(int &a, int &b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

int peakElement(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid < end && arr[mid] > arr[mid + 1])
        {
            return mid;
        }

        if (mid > start && arr[mid - 1] > arr[mid])
        {
            return mid - 1;
        }

        if (arr[mid] >= arr[0])
        {
            start = mid - 1;
        }
        else
        {
            end = mid + 1;
        }
    }

    return -1;
}

// int rotatedSrotedArr(vector<int> arr)
// {
// }

// int findPeak(vector<int> arr)
// {
//     int st = 0;
//     int end = arr.size() - 1;

//     while (st != end)
//     {
//         int mid = st + (end - st) / 2;

//         if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
//         {
//             end = mid;
//         }
//         else if (arr[mid] > arr[mid - 1])
//         {
//             st = mid + 1;
//         }
//     }

//     return st;
// }

int binarySearch(vector<int> arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int findoddElement(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return mid;
        }

        if (mid % 2 == 0 && arr[mid] == arr[mid + 1])
        {
            start = mid + 1;
        }
        if (mid % 2 != 0 && arr[mid] == arr[mid - 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int sqrRootbs(int num)
{
    int start = 0;
    int end = num / 2;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid * mid > num)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return end;
}

int main()
{

    int ans = sqrRootbs(63);
    cout << ans;

    // vector<int> arr1 = {7, 8, 8, 9, 1, 2, 2, 3, 4, 4};
    // vector<int> arr2 = {6, 6, 6, 6, 7, 7, 7, 7, 8};
    // vector<int> arr3 = {5, 6, 7, 1, 2, 3, 4};

    // int pivot = peakElement(arr3);
    // int target = 5;

    // if (pivot == -1)
    // {
    //     int ans = binarySearch(arr3, 0, arr3.size() - 1, target);
    //     cout << ans;
    //     return 0;
    // }

    // if (arr3[pivot] == target)
    // {
    //     cout << pivot << endl;
    //     return 0;
    // }

    // int ans = -1;
    // if (arr3[0] > target)
    // {
    //     ans = binarySearch(arr3, pivot + 1, arr3.size() - 1, target);
    // }
    // else
    // {
    //     ans = binarySearch(arr3, 0, pivot, target);
    // }

    // cout << ans;
}