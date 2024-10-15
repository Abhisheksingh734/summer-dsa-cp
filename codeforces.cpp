#include<bits/stdc++.h>
using namespace std;
// const int N = 1e5+10;

// vector<long long> powers;
// vector<long long> bvalue;

// int bsearch_l(vector<int> &arr, int x){
//     int l = -1;          // arr[l] <= x
//     int r = arr.size(); // arr[r] > x

//     while(r>l+1){
//         int m = l + (r-l)/2;

//         if(arr[m] <= x){
//             l = m;
//         }else{
//             r = m;
//         }
        
//     }

//     return l;
// }
// int arraySum(int a[], int n)
// {
//     int initial_sum = 0;
//     return accumulate(a, a+n, initial_sum);
// }

typedef long long int ll;
// Utility function to find
// GCD of 'a' and 'b'
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
// Returns LCM of array elements
ll findlcm(int arr[], int n)
{
    // Initialize result
    ll ans = arr[0];
 
    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));
 
    return ans;
}

// void absakes(){ 
//     int n,k;
//     cin>>n>>k;

//     priority_queue<int, vector<int>, greater<int>> minH;
//     for (int i = 0;i<k;i++){
//         int num;
//         cin>>num;
//         minH.push(num);
//     }

//     int opp  = 0;

//     while(minH.size() >1){
//         int tops = minH.top();
//         minH.pop();

//         if(tops == 1){
//             opp+= 1;
//         }
//         else{
//             opp += (tops*2) -1;
//         }
        
//     }

//     cout<<opp<<endl;


//  }


int main(){
    int t;
    cin>>t;

    while(t--){

        long long n,x,y;
        cin>>n>>x>>y;

        if(n==0){
            cout<<0<<endl;
            continue;
        }

        if(x>=y){
            cout<<(n+y-1)/y<<endl;

        }else{

            long long time=0, inBlender=0;

            while(n>0){

                long long addf = min(x,y);
                inBlender += addf;

                n-=addf;

                long long blended = min (inBlender, x);
                inBlender -= blended;

                time++;

            }

            cout<<time<<endl;

        }


    }


    return 0;
}

// int m,n,q,t1,t2,d;
//         cin>>m>>n>>q>>t1>>t2>>d;

//         if(t1<t2){
//             swap(t1,t2);
//         }

//         if(d> t1 && d<t2){
//             cout<< max(abs(d-t1),abs(d-t2) )<<endl;;
//         }else{
//             cout<< min(abs(d-t1),abs(d-t2) )<<endl;;
//         }


// void getSubsets(vector<int> &arr, vector<int> &ds,vector<vector<int>> &ans, int i){
//     if(i>=arr.size()) {
//         ans.push_back(ds);
//         return;
//     };


//     ds.push_back(arr[i]);
//     getSubsets(arr, ds,ans,i+1);
//     ds.pop_back();
//     getSubsets(arr,ds, ans, i+1);
// }

// vector<vector<int>> subsets(vector<int> &arr){
//     vector<vector<int>> ans;
//     vector<int> ds;

//     getSubsets(arr, ds, ans,0);

//     return ans;
// }

// const int N = 1e5+10;

// vector<long long> powers;
// vector<long long> bvalue;

// int bsearch_l(vector<int> &arr, int x){
//     int l = -1;          // arr[l] <= x
//     int r = arr.size(); // arr[r] > x

//     while(r>l+1){
//         int m = l + (r-l)/2;

//         if(arr[m] <= x){
//             l = m;
//         }else{
//             r = m;
//         }
        
//     }

//     return l;
// }
// int arraySum(int a[], int n)
// {
//     int initial_sum = 0;
//     return accumulate(a, a+n, initial_sum);
// }

// void absakes(){ 
//     int n,k;
//     cin>>n>>k;

//     priority_queue<int, vector<int>, greater<int>> minH;
//     for (int i = 0;i<k;i++){
//         int num;
//         cin>>num;
//         minH.push(num);
//     }

//     int opp  = 0;

//     while(minH.size() >1){
//         int tops = minH.top();
//         minH.pop();

//         if(tops == 1){
//             opp+= 1;
//         }
//         else{
//             opp += (tops*2) -1;
//         }
        
//     }

//     cout<<opp<<endl;


//  }



// int m,n,q,t1,t2,d;
//         cin>>m>>n>>q>>t1>>t2>>d;

//         if(t1<t2){
//             swap(t1,t2);
//         }

//         if(d> t1 && d<t2){
//             cout<< max(abs(d-t1),abs(d-t2) )<<endl;;
//         }else{
//             cout<< min(abs(d-t1),abs(d-t2) )<<endl;;
//         }




// int main()  
// {
//     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//     int t;
//     cin>>t;
   
      
//     while(t--){
//        int n,m,q;
//        cin>>n>>m>>q;

//        int t1,t2,s1;
//        cin>>t1>>t2>>s1;

//        if(t1>t2){
//         swap(t1,t2);
//        }

//        if(t2>s1 && s1>t1){
//             int d = t2-t1;
//             cout<<d/2<<endl;
//        }else{
//           if(s1>t2){
//             cout<<n-t2<<endl;
//           }else{
//             cout<<t1-1<<endl;
//           }
//        }

        
//     }
//     return 0;
// }
