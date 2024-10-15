/*



    MASTER COMPETITIVE PROGRAMMING 
               _oo0oo_ 
              o8888888o 
              88" . "88 
              (| -_- |) 
              0\  =  /0 
            ___/`---'\___ 
          .' \\|     |// '. 
         / \\|||  :  |||// \ 
        / _||||| -:- |||||- \ 
       |   | \\\  -  /// |   | 
       | \_|  ''\---/''  |_/ | 
       \  .-\__  '-'  ___/-. / 
     ___'. .'  /--.--\  `. .'___ 
  ."" '<  `.___\_<|>_/___.' >' "". 
 | | :  `- \`.;`\ _ /`;.`/ - ` : | | 
 \  \ `_.   \_ __\ /__ _/   .-` /  / 
=====`-.____`.___ \_____/___.-`___.-'===== 




---> stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DO NOT GET STUCK ON ONE APPROACH
*/


#include <bits/stdc++.h>
using namespace std;

#define fastIO() cout.tie(0), cin.tie(0)->sync_with_stdio(0);

using ll = long long;
using db = double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

const int MOD = 1e9+7;
#define pb push_back


int gcd(int a, int b){ return b==0 ? a : gcd(b,a%b);}



	/*




	Why DP?

	- overlapping subproblems
	- Max/Min some value
	- Finding no of ways.
	- dp or greedy.






	To think in DP 

	what is State?? - 

	what is transition?? - how to reach that state

	what is final subProblem?? 


	State - clearly define subprblm understand when saying  dp[i][j][k] what does it mean
	Transition - define a realtion between states, ignores RHS 
	Base case - when does transition fails? call them base case handle them seperately
	final subproblem - 



	*/







// coin combination 1;


/*
state = dp[k] - no of ways to form i
transition = dp[k] = dp[k-coins[i]]
final subproblem = dp[x] 
*/






/*
  -- > removing digits

state - dp[i] min no of steps to make i to 0.
transition - dp[i]	= min(dp[i - digi1], dp[i- digi2], dp[i- digi2]..)
base - dp[0] = 0
final subproblem = dp[n]

*/

	// [ ->_ _ _ i _ _ <- ]




int bs(vi v, int target){
	int lo = 0, hi = v.size()-1;
	int mid;
	while(hi-lo>1){
		mid = (hi + lo)/2;
		if(v[mid] < target){
			lo = mid+1;
		}else{
			hi = mid;
		}
	}

	if(v[lo] == target) cout<<lo<<endl;
	else if (v[hi] == target) cout<<hi<<endl;
	else cout<<"NOt Found"<<endl;

}


int lower_bound(vi v, int target){
	int lo = 0; int hi = v.size()-1;
	int mid;
	while(lo-hi > 1){
		mid = hi + (hi-lo)/2;
		if(v[mid] < target){
			lo = mid+1;
		}else{
			hi = mid;
		}
	}

	if(v[lo] >= target) return lo;
	if(v[hi] >= target) return hi;
	else return -1;
}



int upper_bound(vi v, int target){
	int lo = 0; int hi = v.size()-1;
	int mid;
	while(lo-hi > 1){
		mid = hi + (hi-lo)/2;
		if(v[mid] <= target){
			lo = mid+1;
		}else{
			hi = mid;
		}
	}

	if(v[lo] > target) return lo;
	if(v[hi] > target) return hi;
	else return -1;
}








// find the n-th root of any number upto 2 precision

double esp = 1e-6;

double multiply(double mid, int n){
	double ans = 1.0;

	for(int i=0;i<n;i++){
		ans *= mid;
	}

	return ans;
}

void find_nth_root(double x, int n){
		double lo = 1, hi = x, mid;

		while(hi - lo > esp){
			mid = (hi + lo)/2;
			if( multiply(mid, n) < x ){
				 lo = mid;
			}else{
				hi = mid;
			}
		}

		cout<<setprecision(3)<<lo<<endl;
		cout<<pow(x, 1.0/3)<<endl;
}








bool chai(vector<ll> arr,ll h, ll m){
	ll cnt = 0;

	for(int i=0;i<arr.size();i++){
			if(arr[i] >= h){
				cnt += arr[i] - h;
			}
	}

	return cnt >= m;
}








// int main(){
// 	ll n,m;
// 	cin>>n>>m;
// 	vector<ll> arr(n);
// 	for(int i=0;i<n;i++) cin>>arr[i];
	


// 	ll lo = 0, hi = 1e9, mid;

// 	while(hi- lo > 1){
// 		mid = (hi + lo) /2;

// 		if(chai(arr, mid, m)){
// 			lo = mid;
// 		}else {
// 			hi = mid-1;
// 		}
// 	}

// 	if(chai(arr,hi,m)) cout<<hi<<endl;
// 	else cout<<lo<<endl;

// }







int sol(int M, int N) {
    int left = 0, right = min(M + 2 * N, 100000); // Some reasonable upper bound
    int maxSqLen = 0;

    while (left <= right){
        int mid = left + (right - left) / 2;

        long long reqUnits = 1LL *mid*mid;  

        // Max units we can cover with 2x2 tiles
        long long cov2x2 = min(1LL * N, reqUnits /4)*4;

        // Remaining units to be covered by 1x1 tiles
        long long rem = reqUnits - cov2x2;

        if (rem <= M) {  // Check if 1x1 tiles are enough
            maxSqLen = mid;  // Update max length
            left = mid + 1;  // Try to find a larger square
        } else {
            right = mid - 1;  // Try to find a smaller square
        }
    }

    return maxSqLen;
}

int main() {
    int M, N;
    cin >> M >> N;  // Input the number of 1x1 and 2x2 tiles
    cout << sol(M, N) << endl;  // Output the maximum length of the square
    return 0;
}














/*

state - dp[k] where k is min no of coins to make sum k;
transition - dp[i] = min (dp[k-coins[i]] ) +1 // i from 0 to n-1;
final subpreoblem = dp[n];

*/
#define ll long long


int solve(vector<ll> arr,ll x){
	vector<int> dp(x+1,INT_MAX-1);

	dp[0] = 0;
	for(int i=1;i<=x;i++){
		for(auto j: arr){
			if(i-j >= 0)
			dp[i] = min(dp[i], dp[i-j] + 1);
		}
	}

	dp[x] = (dp[x] == INT_MAX-1 ? -1 : dp[x]);
	return dp[x];
}


//dp[i] -> no of ways to form i
// dp[i] -> sum of all dp[i - k];
//dp[x]

// int solve(vector<ll> wt, ll n){
// 	// initialisation

// 	ll dp[n+1][7];

// 	for(int i=0;i<=n;i++){
// 		for(int j=0;j<=6;j++){
// 			if(i==0) dp[i][j] = 0;
// 			if(j==0) dp[i][j] = 1;
// 		}	
// 	}

// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=6;j++){
// 			if(wt[i-1] - j >=0){
// 				dp[i][j] = dp[i-1][wt[i-1]-j] ,dp[i-1][j];
// 			}else{
// 				dp[i][j] = dp[i-1][j];
// 			}

// 		}
// 	}

// 	return dp[n][6];
// }








int bsearch_l(vector<char> &arr, int x){
	int l = -1;			 // arr[l] <= x
	int r = arr.size();	// arr[r] > x

	while(r>l+1){
		int m = l + (r-l)/2;

		if(arr[m] <= x){
			l = m;
		}else{
			r = m;
		}
		
	}

	return l;
}










// int main(){

// 	int n, x;
// 	cin>>n>>x;
// 	vector<int> coins(n);
//     for (int i = 0; i < n; i++) {
//     	int num;
//     	cin>>num;
//         coins.push_back(num);
//     }
// 	vector<int> dp(x+1, -1);

// 	int res = minimumCoins(x,coins, dp);
// 	cout<<res<<endl;
// }




/// no of ways

	// state = dp[i] where i is no of way to make sum i;
	// transition = dp[i] = dp[i-1] + dp[i-2]...dp[i-6];
	// final subproblem = dp[n];

	
	int noOfWays_itr(int n){
		vector<int> dp(n+1, 0);

		dp[0] = 1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=6;j++){
				if(i-j>=0)
				dp[i] = (dp[i] + dp[i - j])%MOD;
			}
		}

		return dp[n];

	}


	long long noOfWays(int n, vector<long long> &dp){
		if(n<0) return 0;
		if(n==0) return 1;

		if(dp[n] != -1) return (dp[n])%MOD;

		dp[n] = 0;
		for(int i=1;i<=6;i++){
			dp[n] = (dp[n] + noOfWays(n-i, dp))%MOD;
		}

		return dp[n];
	}

