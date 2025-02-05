#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int t = st.top();
    st.pop();
    insert(st, ele);
    st.push(t);
}

void reverseStack(stack<int> &st)
{

    if (st.empty())
    {
        return;
    }

    int ele = st.top();
    st.pop();

    reverseStack(st);

    insert(st, ele);
}

int main()
{
    vector<int> arr = {2, 3, 6, 1};
    stack<int> st;

    for (int x : arr)
    {
        st.push(x);
    }

    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}