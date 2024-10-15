#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &t)
{
    /*
                  i=2         j=6
        temp = [73,74,75,71,69,72,76,73]
            stack = [ 73 ,
        ans = [ (j-i), (j-i) , (j-i)  ]

    */
    stack<int> st;
    vector<int> ans(t.size(), 0);
    for (int i = 0; i < t.size(); i++)
    {

        while (!st.empty() && t[st.top()] < t[i])
        {

            int top = st.top();
            st.pop();

            ans[top] = i - top;
        }

        st.push(i);
    }

    return ans;
}

int main()
{
}