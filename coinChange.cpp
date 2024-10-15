#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
// #define ll long long;
int dp[10010];

int func(int amount, vector<int> &coins){
    if(amount == 0) return 1;
    if(dp[amount] != -1) return dp[amount];


    int ans = 0;
    for(int coin: coins){
        if(amount-coin >=0)
        ans += func(amount - coin, coins);
    }

    return dp[amount] = ans;

}

 int coinChange(vector<int>& coins, int amount) {
    memset(dp, -1, sizeof(dp));
    int ans = func(amount, coins);
    return ans;
}
   

void absake(){ 
    
    vector<int> coins = {1,2,5};
    cout<< coinChange(coins, 5);

 }

int main()
{
    int T=1;
    // cin >> T;
    while(T--){
         absake();
    }
    return 0;
}