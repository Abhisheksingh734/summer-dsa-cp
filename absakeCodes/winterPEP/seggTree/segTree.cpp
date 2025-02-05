#include <bits/stdc++.h>
using namespace std;

struct segTree
{
    int n;
    vector<int> st;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
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

    void query(int start, int end, int l, int r, vector<int> &st)
    {
    }

    int query(int start, int end, int l, int r, int node)
    {
        // no overlap - return 0;

        if (l > end || r < start)
        {
            return 0;
        }

        // complete overlap - return node;
        if (start >= l && r >= end)
        {
            return st[node];
        }

        // partial

        int mid = (start + end) / 2;

        int left = query(start, mid, l, r, 2 * node + 1);

        int right = query(mid + 1, end, l, r, 2 * node + 2);

        return left + right;
    }

    void update(int start, int end, int node, int index, int val)
    {

        if (start == end)
        {
            st[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid)
        {

            update(start, mid, 2 * node + 1, index, val);
        }
        else
        {

            update(mid + 1, end, 2 * node + 2, index, val);
        }

        st[node] = st[2 * node + 1] + st[2 * node + 2];
        return;
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y)
    {
        update(0, n - 1, 0, x, y);
    }
    /* data */
};

int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    segTree segmentTree;

    segmentTree.init(v.size());
    segmentTree.build(v);

    cout << segmentTree.query(3, 5) << "\n";
    cout << segmentTree.query(0, 2) << "\n";

    segmentTree.update(0, 2);

    cout << segmentTree.query(3, 5) << "\n";
    cout << segmentTree.query(0, 2) << "\n";
}