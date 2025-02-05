#include <bits/stdc++.h>
using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.back();
    
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;
    int day = 1;

    for (int i =1; i<=n; i++)
    {

        if()

        for (int j = 0; j < costs.size(); j++)
        {
            if (j == 0)
                day = 1;
            if (j == 1)
                day = 7;
            if (j == 2)
                day = 30;

            if (i - day >= 0)
                dp[i] = min(dp[i], dp[i - day] + costs[j]);
        }
    }

    return dp[n ];
}

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};

    cout << mincostTickets(days, costs);
}