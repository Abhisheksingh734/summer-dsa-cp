/*
Given an array a of N integers. Given Q queries 
and in each query given a number X, print count
of that number in array.
constraints

1<= N <= 10^5
1<= a[i] <= 10^7
1<= Q <= 10^5

*/


#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int M = 1e9+7;

void absake(){
	long long n,k,q;
    cin >>n>>k>>q;
    vector<long long> dist;
    vector<long long> time;
    for(int i=0;i<k;i++){
        long long h;
        cin>>h;
        dist.push_back(h);
    }
    for(int i=0;i<k;i++){
        long long j;
        cin >> j;
        time.push_back(j);
    }

    while(q--){

    	long long d;
    	cin>>d;

    	auto it = lower_bound(dist.begin(), dist.end(),d)- dist.begin();
    	it--;
    	if(it == -1){
    		long long distance = dist[0];
    		long long t = time[0];

    		cout<<(d*t)/distance<<" ";

    	}else{

    		long long distance = dist[it+1] - dist[it];
    		long long t = time[it+1] - time[it];

    		cout<<((d-dist[it]) *t )/distance +time[it]<<" ";
    	}

    	


    }
    cout<<endl;
}

int main(){
	int Q;
	cin>>Q;

	while(Q--){
		
		absake();
	}

	return 0;
}