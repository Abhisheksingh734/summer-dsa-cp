#include <bits/stdc++.h>
using namespace std;

struct segTree
{
    int n;
    vector<int> st, lazy;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build(int start, int end, int node, vector<int> &v)
    {
        if (start == end)
        {
            st[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * node + 1, v);
        build(mid + 1, end, 2 * node + 2, v);
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void build(vector<int> &v)
    {
        build(0, v.size() - 1, 0, v);
    }

    int query(int start, int end, int l, int r, int node)
    {
        if (l > end || r < start)
            return 0;

        // lazy propagation

        if (lazy[node] != 0)
        {
            // pending updates
            // update the segment tree node with value
            st[node] += lazy[node] * (end - start + 1);

            // check for leaf node
            if (start != end)
            {

                // propagate the updated value
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (start >= l && end <= r)
            return st[node];
        int mid = (start + end) / 2;
        int left = query(start, mid, l, r, 2 * node + 1);
        int right = query(mid + 1, end, l, r, 2 * node + 2);
        return left + right;
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int start, int end, int node, int l, int r, int val)
    {
        if (l > end || r < start)
            return;

        // lazy propagation

        if (lazy[node] != 0)
        {
            // pending updates
            // update the segment tree node with value
            st[node] += lazy[node] * (end - start + 1);

            // check for leaf node
            if (start != end)
            {

                // propagate the updated value
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (start >= l && end <= r)
        {

            st[node] += val * (end - start + 1);
            if (start != end)
            {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        // partial overlap

        int mid = (start + end) / 2;

        update(start, mid, 2 * node + 1, l, r, val);
        update(mid + 1, end, 2 * node + 2, l, r, val);

        st[node] = st[node * 2 + 1] + st[2 * node + 2];
    }

    void update(int l, int r, int x)
    {
        update(0, n - 1, 0, l, r, x);
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    segTree segmentTree;

    segmentTree.init(v.size());
    segmentTree.build(v);

    cout << segmentTree.query(0, 4) << "\n";
    segmentTree.update(0, 1, 10);
    cout << segmentTree.query(0, 4) << "\n";

    // cout << segmentTree.st[0];
}