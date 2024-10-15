/*
Given T test cases and in each TC a number N.
Print its factorial for each test case % M
where M = 10^9 + 7

constraints

1<= T <= 10^5
1<= M <= 10^5
*/


#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int M = 1e9+7;

long long fact[N];

void absake(){

	int n;
	cin>>n;
	cout<<fact[n]<<endl;

}


int main(){

	//pre-computation
	fact[0] = fact[1] = 1;
	for(int i=2;i<N;i++){
		fact[i] = fact[i-1] *i;
	}
	int T;
	cin>>T;

	while(T--){

		absake();
	}

	return 0;
}