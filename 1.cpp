#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;


// index of the rightmost element which is less than or equal to x
int bsearch_l(vector<int> &arr, int x){
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

// index of the leftmost element which is greater than or equal to x
int bsearch_r(vector<int> &arr, int x){
	int l = -1;  // arr[m] < x
	int r = arr.size(); // arr[m] >= x

	while(r>l+1){
		int m = l+ (r-l)/2;

		if(arr[m] < x){
			l = m;
		}else{
			r = m;
		}
	}

	return r;
}




int c(vector<int> &arr){
	unordered_map<int,int> mp;

	for(int i=0;i<arr.size();i++){
		mp[arr[i]]++;
	}

	int cnt = 0;
	for(auto x: mp){
		if(x.second>1){
			cnt++;
		}
	}

	cout<<cnt<<endl;
}


























int main(){
	

	return 0;
}