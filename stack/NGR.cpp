#include <bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here
    vector<long long> v;
    stack<long long> st;

    for (long i = n - 1; i >= 0; i--)
    {

        while (st.size() > 0 && arr[i] >= st.top())
        {
            st.pop();
        }

        if (st.empty())
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(st.top());
        }

        st.push(arr[i]);
    }

    reverse(v.begin(), v.end());

    return v;
}

int print(vector<int> v)
{
    for (int ele : v)
    {
        cout << ele << " ";
    }
}

void largestRectangleArea(vector<int> &h)
{
    int n = h.size();
    vector<int> leftsmall(n), rightsmall(n);
    stack<int> st;
    // computing left small array
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && h[st.top()] >= h[i])
        {
            st.pop();
        }
        if (st.empty())
            leftsmall[i] = 0;
        else
            leftsmall[i] = st.top() + 1;

        st.push(i);
    }
    print(leftsmall);
    cout << endl;
    // clear the stack
    while (!st.empty())
        st.pop();
    // computing right small array
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && h[st.top()] >= h[i])
        {
            st.pop();
        }
        if (st.empty())
            rightsmall[i] = n - 1;
        else
            rightsmall[i] = st.top() - 1;

        st.push(i);
    }
    print(rightsmall);
    // computing final ans
    cout << endl;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int temp = (rightsmall[i] - leftsmall[i] + 1) * h[i];
        cout << temp << " ";
        maxi = max(maxi, temp);
    }
    // return maxi;
}

int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3};
    largestRectangleArea(v);
}