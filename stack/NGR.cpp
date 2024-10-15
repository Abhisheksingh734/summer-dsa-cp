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
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
// vector<string> reconstruct_itinerary(vector<vector<string>> tickets)
// {
//     //     Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
//     // Output: ["JFK","MUC","LHR","SFO","SJC"]
//     unordered_map<pair<string, pair<int, int>>, int, pair_hash> mp;

//     for (int i = 0; i < tickets.size(); i++)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//             mp[tickets[i][j], {i, j}]++
//         }
//     }
// }

vector<int> distinct_array(vector<int> arr, int k)
{

    unordered_map<int, int> mp;
    int i = 0, j = 0;
    vector<int> ansMax;
    int N = arr.size();
    int count = 0;
    while (j < N)
    {
        if (mp[arr[j]] == 0)
        {
            count++;
        }
        mp[arr[j]]++;

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ansMax.push_back(count);

            // slide window
            mp[arr[i]]--;
            if (mp[arr[i]] == 0)
            {
                count--;
            }

            i++;
            j++;
        }
    }

    return ansMax;
}


	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int, vector<int>, greater<int>> minH;
	    
	    for(int i=0;i<n;i++){
	        minH.push(arr[i]);
	        
	        if(minH.size() > k){
	            minH.pop();
	        }
	    }
	    
	    vector<int> ans;
	    while(minH.size() > 0){
	        ans.push_back(minH.top());
	        minH.pop();
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}

int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3};
    // largestRectangleArea(v);

    vector<int> ans = distinct_array({1, 2, 1, 3, 4, 2, 3}, 4);
    print(ans);
}