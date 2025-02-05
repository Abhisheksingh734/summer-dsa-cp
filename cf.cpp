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

// #define fastIO() cout.tie(0), cin.tie(0)->sync_with_stdio(0);
#define Magic                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using ll = long long;
using db = double;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

const int MOD = 1e9 + 7;
#define pb push_back

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

template <typename T1, typename T2>

struct less_second
{
    typedef pair<T1, T2> type;
    bool operator()(type const &a, type const &b) const
    {
        return a.second < b.second;
    }
};

// int bsearch_l(vector<ll> &arr, int x){
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

// 5
// 1
// 4
// 3
// 11

bool cmp(pair<int, int> &a,
         pair<int, int> &b)
{
    return a.second > b.second;
}

// Function to sort the map according
// to value in a (key-value) pairs
void sortmap(map<int, int> &M)
{

    // Declare vector of pairs
    vector<pair<int, int>> A;

    // Copy key-value pair from Map
    // to vector of pairs
    for (auto &it : M)
    {
        A.push_back(it);
    }

    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);

    // Print the sorted value
    // for (auto& it : A) {

    //     cout << it.first << ' '
    //         << it.second << endl;
    // }
}

void absake()
{
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        absake();
}

/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠤⢲⣦⡀⠀⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣠⠖⠚⠓⠒⠒⠲⠿⣍⣛⣻⣦⣷⢠⣻⣀⠤⠤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠔⡿⠓⠲⠬⢥⡤⠤⠤⠤⠤⣤⣀⣀⣈⣻⣿⣿⠓⠉⣀⡤⠔⢶⣻⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⢤⠞⠁⣼⠀⠀⠀⠀⠀⠀⠰⠶⢌⣽⡶⠟⢏⡁⢈⣉⣭⣷⡯⣝⠒⢦⣄⠙⠷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⣵⠿⣳⡟⠉⠉⠿⠀⠀⡀⠀⠀⣀⣀⣢⣾⣿⡚⠓⠒⠒⠒⠻⢿⣟⣧⡀⢠⣢⡻⠙⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⢿⣟⣲⢿⣷⢀⣤⣠⣄⣈⢿⣷⣤⣷⣻⡓⠒⠻⠭⢷⡄⠒⠲⢶⣦⣬⣻⣏⢦⡈⢿⣆⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢖⣩⠷⢎⣙⣿⣿⣼⡼⣿⣟⣽⣻⢯⢿⠞⣌⠙⢳⡕⠀⠙⠲⣶⠤⢄⡠⣄⡈⠛⣿⣿⣧⢳⣌⢻⡆⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠗⠉⢀⣾⠟⠒⡿⣫⡿⡾⢫⢟⡏⠉⢸⡀⠑⢾⡆⢤⣻⣶⣤⣘⣲⣿⣶⡽⠿⣯⠲⣌⣇⢹⣷⣿⣆⠸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⡼⠀⣿⢣⣧⠋⣸⠀⣰⢀⣿⣆⠀⠰⣄⠙⣧⣨⣿⣿⣿⣯⣿⣦⠘⣷⡌⢻⡄⠿⣆⠟⣆⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⡇⡼⣹⠈⢣⠆⡇⣰⣻⣼⣿⣽⣷⣦⣹⣿⣟⣯⠉⠘⣿⠏⠃⠀⣷⣽⡿⣾⡹⣷⣹⣧⡈⢺⡀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⢾⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⣷⣱⣽⡀⢸⣆⢳⣿⣇⣷⡿⠖⠿⠷⢦⣙⣆⠩⡗⠀⠀⠀⠀⠀⡯⠿⠳⣟⠻⣽⣄⢧⠈⠳⣷⡀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡇⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣿⣿⣷⣸⣿⡀⣿⣅⠛⠇⠀⠀⠀⠀⢈⠙⠂⠀⠀⠀⠀⠀⣸⣿⠀⢠⣜⢦⠘⢿⣮⣷⡀⠀⠙⢦⡀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢯⣇⠙⢄⣀⠀⠀⠀⢀⣀⡠⣴⣾⣫⠵⠛⣿⣻⠿⣷⣹⣾⣷⡠⡀⠀⠀⠀⠻⠦⠀⣀⠔⠀⠀⣴⣿⣸⣧⡀⠳⣝⠳⢴⡙⢞⣏⠢⡀⠀⠹⡄⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⢀⣀⣀⣈⣻⣤⣀⠈⠉⠻⠿⢿⣺⣿⡵⣶⢶⣦⠀⠘⣿⢷⣾⢿⣿⡋⢙⣮⣄⡀⠀⠀⠉⠈⠀⠀⢀⢞⣿⣼⣿⣿⣿⣆⡀⠙⢦⣝⣮⠛⢷⡙⢆⠀⣷⠀⠀⠀⠀
/// ⠀⠀⠀⢠⡴⢟⣫⠤⠖⠒⠛⢛⣲⣿⣿⣿⠟⠋⢱⣿⣴⣷⣿⣹⢃⣀⣘⠃⢩⢿⣫⣥⣿⠧⢿⣿⣗⡶⣤⣄⣀⣴⣷⣻⣿⣿⠻⠘⣏⠛⢿⣦⣀⠱⢤⣉⡑⠛⠮⢿⣹⠀⠀⠀⠀
/// ⠀⢠⢖⠵⠊⠁⢀⡤⠖⣲⣿⣿⣟⣻⣿⣋⠀⠀⠈⢿⣿⡿⠟⣵⣿⣿⣿⣷⡏⠈⢿⡿⣷⣤⣼⢿⣿⣿⢶⣯⣭⣵⣾⢿⣿⠿⢦⡀⢹⠀⠈⣏⠉⠉⢻⣶⣯⡑⠦⣄⠈⠳⣄⠀
/// ⠀⠹⠁⠀⠀⣞⢁⡾⢽⣯⣝⣛⣛⣯⣭⣽⣿⣷⣶⣤⣤⣴⣿⣿⣿⣿⣿⣿⡀⣀⣼⣀⠈⠙⠛⠷⣾⡿⢿⡟⣿⠟⠁⣈⣥⡴⠾⠷⢾⡄⠀⣿⠀⠀⠈⢇⠘⣿⣤⣀⠑⢦⡘⢧⠀
/// ⠄⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⡿⠛⣻⢏⡽⣯⡄⠘⣏⣿⡏⠈⠙⠓⠶⣤⣀⠀⠙⢿⣿⡇⢀⡿⠋⠁⠀⢀⣀⣸⡇⠀⣟⣀⠀⠀⠀⠙⠃⣿⡎⠑⣤⡙⣌⡇
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⡥⣖⡯⠖⢋⣡⡞⣼⣿⠀⠀⢹⣿⣷⠀⠀⣀⡀⠀⠉⠻⣦⠀⢿⣿⡿⠁⣠⡶⠟⠋⠉⠹⣆⣸⣿⣿⠀⣀⡤⣤⡀⣿⠇⠀⢸⠳⡜⡇
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣈⣿⣿⣿⣿⣿⣿⣏⢿⣗⠒⠊⠉⢸⠁⡿⡏⠀⢀⣿⡿⣁⠤⢶⣿⣽⡆⠀⠀⠘⢷⡈⠉⣡⠾⠋⠀⠀⣠⣆⢠⣿⣿⣿⡟⢀⣷⠒⢺⣧⡏⠀⠀⢸⠀⢹⣹
/// ⠀⠀⠀⠀⠀⠀⠀⡠⢪⠟⡽⠙⢶⣾⣿⣿⣿⣷⡻⣦⡀⠀⠀⢣⣇⡇⢀⡞⣸⠏⠁⠀⠀⡇⢻⡀⠀⠀⣾⣶⡟⣿⣥⡄⠀⠀⢠⣇⣼⡶⣿⣿⠋⣸⣾⣷⣚⣽⡟⠀⠀⠀⣏⠀⡼⣿
/// ⠀⠀⠀⠀⠀⢀⠎⡴⣣⣾⠟⣡⠞⢹⡿⣿⢿⣿⣿⣿⣷⣄⠀⠈⠻⡹⣼⠀⣿⡄⠀⠀⠀⠉⠻⣷⡀⠀⠙⠿⠇⣿⠿⠇⠀⠀⢠⡿⠋⢇⢹⣟⢷⠫⣿⣟⡿⠋⠀⠀⣠⣾⢞⡜⠁⡿
/// ⠀⠀⠀⠀⠀⡼⡼⣵⠏⡏⣰⠃⠀⢾⡇⠈⠻⣿⣮⡉⠹⣿⣧⣄⡀⠙⣇⠀⠸⣿⣄⡀⠀⠀⠀⠈⢉⣧⡴⠀⠠⡄⣀⡤⠤⠴⠋⠁⠀⠈⢻⣿⣾⣤⡿⠋⠀⠀⠀⣉⣽⠿⠋⠀⣰⠃
/// ⠀⠀⠀⠀⠀⣿⣽⠋⠀⡇⡇⠀⠀⠘⣷⢠⣶⢮⣻⣿⣦⠈⠛⠙⠹⣷⠘⢦⣤⣿⣳⣭⣑⣒⣒⣺⣿⢿⣀⣀⣀⣿⣧⣀⣀⣀⡤⠴⠒⣶⣿⣏⣾⡿⠁⠀⠀⠀⠉⠉⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⢻⡏⠀⠀⢳⣇⠀⠀⠀⠈⠈⣿⣾⣿⣿⣮⣿⣦⠀⠀⢿⣶⡫⣿⣿⣿⣿⣿⡹⣯⣊⠁⠉⠉⠉⠉⢙⣮⣷⣶⡤⣤⣶⣿⣿⣟⣾⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠸⣿⣦⡀⠀⠙⠦⠀⠀⢀⣼⠿⣽⣿⣯⣷⣼⡷⢾⣻⣾⣿⠞⢿⢻⡷⠻⣿⣏⡙⢝⣻⡾⡖⠒⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣎⠣⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⣴⣋⣉⣩⣿⣿⢿⣟⣷⣾⣯⡟⢱⡇⠀⠘⣿⠣⡀⣈⣻⣿⣿⣿⣷⣷⣶⣿⣿⣟⠋⡿⣹⣿⣿⣿⣿⢟⣏⠺⠿⠶⠭⠷⠂⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⢹⣮⣾⣿⡿⢋⣶⢸⡇⠀⠀⠈⢷⡑⠈⢻⣟⠛⠛⠿⠋⠙⠓⣭⣿⣹⣵⣿⣿⣿⣿⣿⠈⠻⣷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢟⣛⡭⠶⢾⡿⠃⠀⠀⢸⢹⣾⣇⠀⠀⠀⠀⠻⣟⣿⡏⠀⠀⠀⠀⢰⣿⣿⢿⡇⣿⣿⣿⣿⣟⡏⠀⠀⠀⠉⠙⠓⠒⠂⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡟⠀⠀⠀⢰⣿⢸⣿⢿⡀⠀⠀⠀⠀⢸⣿⣣⠀⠀⠀⢠⣿⡟⣷⣾⣿⢿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠁⠀⠀⠀⠘⡿⡿⢿⣏⣧⠀⠀⠀⢀⣾⣿⠿⠀⢀⣴⣿⣿⢿⡹⡇⣿⠈⣿⣿⡟⣾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⢳⢧⠈⢿⣿⠀⠀⢀⣼⣿⠕⠁⣠⣾⡿⣻⠏⠀⢹⣹⣿⣆⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣷⠀⠀⠀⠀⠈⣏⢧⠀⢻⣧⠶⣋⠿⠋⣀⣾⣟⣿⠞⠁⠀⠀⠀⢯⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣇⠀⠀⠀⠀⠸⡜⣆⠈⢷⣿⠀⢠⣾⣿⠟⢻⡏⠀⠀⠀⠀⠀⠘⣿⣿⠏⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡻⣿⣿⣦⡀⠀⠀⠀⢧⠘⣆⠈⢷⠒⠛⢻⡿⠄⠘⣧⠀⠀⠀⠀⠀⢰⣷⣹⠀⠙⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣷⣝⣿⣿⣷⣄⠀⠀⠈⢇⠸⡄⠈⣇⠀⠀⢻⣆⠀⠘⣇⠀⠀⣠⣾⣽⢹⡟⠀⢰⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣾⢻⠙⢿⣿⡇⠀⠀⠈⢧⢳⠀⢸⡀⠀⠀⢻⣆⠀⢻⡄⢠⣿⣯⣽⣓⣧⣤⠾⢹⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣼⡇⠀⠙⣿⠀⠀⠀⠈⢏⢧⠀⣇⠀⠀⠀⢻⣆⠀⢷⠘⣿⣮⡻⣿⠁⠀⢀⣯⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠘⡾⡄⢸⠀⠀⠀⠈⢻⣆⠈⢷⣷⣾⣟⣻⣶⣿⡿⠛⢿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣦⣀⠀⠀⠀⠀⠀⢳⣇⠘⡆⠀⠀⠀⠀⠻⣶⢺⡏⢹⡟⠀⠉⠁⠀⠀⠀⢩⣍⠙⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣟⣿⣿⣿⣧⠀⢀⣤⣤⡸⣸⠀⡇⠀⠀⠀⠀⠀⠙⣿⣷⢡⣿⣶⣄⠀⠀⣄⠀⣦⣍⠙⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡿⢿⡙⠿⠀⢸⡟⢲⣷⡿⡄⢿⠀⠀⠀⠀⠀⠀⠘⣏⢸⣇⣍⢻⣷⣀⢻⣦⣤⣌⡙⣦⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣯⢷⠀⠀⠸⡇⠀⢿⣧⡇⢸⠀⠀⠀⠀⠀⠀⠀⣼⢸⣿⣯⠀⣿⣿⣷⣝⣿⣻⣿⣼⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣎⣧⠀⠐⣇⠀⠘⣽⣿⡸⡆⠀⠀⠀⠀⠀⠀⠈⠋⠈⠻⣼⣿⢶⢿⣿⣯⡻⣿⣿⣾⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡼⡆⠀⣿⡀⠀⣿⢿⡇⢷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣾⢧⠈⠙⠿⣮⠟⠉⠙⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⢻⢠⣿⡇⠀⠹⣄⢳⣜⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡏⠪⠳⢤⣄⣀⠀⠀⠀⠈⢣⠀⠀⠀⠀⠀⠀⠀⠀⠀
/// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣎⣿⡟⡇⠀⠀⠈⢻⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⡄⠀⠀⠀⠙⢧⡀⢀⡄⠈⡇