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


int main(){
	ios::sync_with_stdio(false);

	int n,m;cin>>n>>m;
	vector<int> a(n);
	vector<int> b(m);

	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];

	a.push_back(INT_MAX);
	b.push_back(INT_MAX);

	int i=0,j=0,k=0;
	vector<int> res(n+m);
	

	while(i<n || j<m){

		if(a[i] < b[j]){
			res[k++] = a[i++];
		}else{
			res[k++] = b[j++];
		}
	}

	for(int x: res) cout<<x<<" ";

	cout<<endl;


}
