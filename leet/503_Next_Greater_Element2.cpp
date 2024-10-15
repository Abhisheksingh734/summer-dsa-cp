#include <bits/stdc++.h>
using namespace std;

int maxx = 1e6 + 1;

vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> st;

    vector<int> ans(nums.size(), -1);

    for (int j = 0; j < 2; j++)
    {

        for (int i = 0; i < nums.size(); i++)
        {

            while (!st.empty() && nums[st.top()] < nums[i]) // monotonic stack - decreasing
            {

                int top = st.top();
                st.pop();

                ans[top] = i;
            }

            st.push(i);
        }
    }
    return ans;
}

int main()
{

    vector<int> arr = {1, 2, 1};
    vector<int> ans = nextGreaterElements(arr);
    // 2, -1, -1

    for (auto x : ans)

        cout << arr[x] << " ";
    return 0;
}