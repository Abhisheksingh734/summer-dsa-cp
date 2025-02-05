#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int ele)
{
    if (st.size() == 0 || st.top() <= ele)
    {
        st.push(ele);
        return;
    }

    int t = st.top();
    st.pop();
    insert(st, ele);
    st.push(t);
}

void sortStack(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }

    int top = st.top();
    st.pop();
    sortStack(st);
    insert(st, top);
}

int main()
{

    vector<int> arr = {1, 5, 0, 3, 2};
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