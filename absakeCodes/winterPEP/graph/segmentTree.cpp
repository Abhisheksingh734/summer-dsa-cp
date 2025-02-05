#include <bits/stdc++.h>
using namespace std;

void build(int start, int end, int node, vector<int> &v, vector<int> &arr)
{
    if (end == start)
    {
        v[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;

    build(start, mid, (2 * node) + 1, v, arr);

    build(mid + 1, end, (2 * node) + 2, v, arr);

    v[node] = v[2 * node + 1] + v[2 * node + 2];
}

int query(int start, int end, int l, int r, int node, vector<int> &v)
{

    // non overlapping case
    if (start > r || end < l)
    {
        return 0;
    }

    // complete overlap
    if (start >= l && end <= r)
    {
        return v[node];
    }

    int mid = (start + end) / 2;

    int left = query(start, mid, l, r, (node * 2) + 1, v);
    int right = query(mid + 1, end, l, r, (2 * node) + 2, v);

    return left + right;
}

void update(int start, int end, int node, int index, int val, vector<int> &v)
{

    if (start == end && start == index)
    {
        v[node] = val;
        return;
    }

    int mid = (start + end) / 2;

    if (mid >= index)
    {
        // leftsubtree
        update(start, mid, (2 * node) + 1, index, val, v);
    }
    else
    {
        // rightsubtree
        update(mid + 1, end, (2 * node) + 2, index, val, v);
    }

    v[node] = v[(2 * node) + 1] + v[(2 * node) + 2];

    return;
}

int main()
{
    vector<int> arr = {5, 3, 8, 6, 7, 2, 1, 4, 9, 0};

    vector<int> segg(4 * arr.size());

    build(0, 9, 0, segg, arr);

    for (auto x : segg)
    {
        cout << x << " ";
    }
    cout << endl;
    // cout << query(0, 9, 5, 9, 0, segg);
    update(0, 9, 0, 5, 9, segg);
    cout << query(0, 9, 4, 6, 0, segg);
}