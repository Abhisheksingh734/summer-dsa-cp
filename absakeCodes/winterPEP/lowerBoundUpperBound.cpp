#include <bits/stdc++.h>
using namespace std;
int upper_bound(vector<int> v, int target)
{
    int lo = 0;
    int hi = v.size() - 1;
    int mid;
    while (lo - hi > 1)
    {
        mid = hi + (hi - lo) / 2;
        if (v[mid] <= target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }

    if (v[lo] > target)
        return lo;
    if (v[hi] > target)
        return hi;
    else
        return -1;
}

int lower_bound(vector<int> v, int target)
{
    int lo = 0;
    int hi = v.size() - 1;
    int mid;
    while (lo - hi > 1)
    {
        mid = hi + (hi - lo) / 2;
        if (v[mid] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }

    if (v[lo] >= target)
        return lo;
    if (v[hi] >= target)
        return hi;
    else
        return -1;
}

int main()
{
}