#include <bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int> &nums)
{
    /*
    INTUITION
     - somehow if I get "previous greater" of nums[i] let say X, and after that
       find "previous minimum" for all nums[i] let say Y

       if compare Y < X ... then we found the pair/?????



    */

    // vector<int> nextGreater(nums.size(), -1);
    // vector<int> previousGreater(nums.size(), -1);
    // stack<int> st;

    // for(int i=0;i<nums.zie();i++){

    //     while(!st.empty() && nums[st.top()] < arr[i]){
    //         int top = st.top(); st.pop();

    //         nextGreater[top] = i;
    //     }

    //     st.push(i);
    // }

    // for(int i=0;i<nums.size();i++){

    //     while(!st.empty() && nums[st.top()] > arr[i]){

    //         st.pop();
    //     }

    //     if(!st.empty()){
    //         previousGreater[i] = st.top();
    //     }

    //     st.push(i);
    // }

    stack<int> st;

    int last = INT_MIN;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] < last)
            return true;

        while (!st.empty() && nums[st.top()] < nums[i])
        {
            last = nums[st.top()];
            st.pop();
        }
        st.push(i);
    }

    return false;
}

int main()
{
}