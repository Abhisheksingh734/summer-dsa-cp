#include <bits/stdc++.h>

using namespace std;

int knapsack(int weight[], int val[], int W, int n)
{

    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (weight[n] <= W)
    {
        return max(val[n] + knapsack(weight, val, W - weight[n], n - 1),
                   knapsack(weight, val, W, n - 1));
    }

    else if (weight[n] > W)
    {
        knapsack(weight, val, W, n - 1);
    }
}

int main()
{
    int w[] = {1, 3, 4, 5};
    int v[] = {1, 4, 5, 7};
    int W = 7;

    cout << knapsack(w, v, W, 4);
}