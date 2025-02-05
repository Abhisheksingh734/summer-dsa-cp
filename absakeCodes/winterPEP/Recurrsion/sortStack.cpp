#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int ele)
{
    if (st.empty() || st.top() <= ele)
    {
        st.push(ele);
        return;
    }

    int t = st.top();
    st.pop();
    insert(st, ele);

    st.push(t);
    return;
}

void sortStack(stack<int> &st)
{
    if (st.size() == 0)
        return;

    int t = st.top();
    st.pop();

    sortStack(st);
    insert(st, t);

    return;
}

int main()
{

    vector<int> arr = {3, 6, 2, 8, 1};
    stack<int> st;

    for (auto x : arr)
    {
        st.push(x);
    }

    sortStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}