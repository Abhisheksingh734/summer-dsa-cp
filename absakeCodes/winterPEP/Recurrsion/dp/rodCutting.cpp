#include <bits/stdc++.h>
using namespace std;

int rodCutting(int n, vector<int> &profit)
{
    if (n == 0)
        return 0;

    int maxy = 0;
    for (int i = 1; i < profit.size() && i <= n; i++)
    {

        if (n >= i)
        {
            int inc = profit[i - 1] + rodCutting(n - i, profit);
            maxy = max(maxy, inc);
        }
    }

    return maxy;
}

int rodCuttingGivenCuts(vector<int> cuts, vector<int> profits, int length)
{

    if (length == 0)
        return 0;

    int maxy = 0;

    for (int i = 0; i < cuts.size(); i++)
    {
        int inc = 0;
        if (cuts[i] <= length)
        {
            inc = rodCuttingGivenCuts(cuts, profits, length - cuts[i]) + profits[i];
        }

        maxy = max(inc, maxy);
    }

    return maxy;
}

int main()
{
    vector<int> profit = {2, 1, 3};
    vector<int> cuts = {1, 2, 3};

    int n = 5;
    cout << rodCutting(n, profit) << endl;
    // cout << rodCuttingGivenCuts(cuts, profit, n);
}