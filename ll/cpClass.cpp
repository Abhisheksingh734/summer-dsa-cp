#include <bits/stdc++.h>

using namespace std;

void absake(int n, vector<vector<int>> &q) {
    vector<int> arr(n + 1, 0);  

    for (auto &x : q) {
        arr[x[0]] += x[2];
        if (x[1] + 1 < n)
            arr[x[1] + 1] -= x[2];
    }

    for (int i = 1; i < n; ++i) {
        arr[i] += arr[i - 1];
    }


    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int q;
    cin >> q;  
    while (q--) {
        int n, m;
        cin >> n >> m; 
        vector<vector<int>> queries(m, vector<int>(3));

        for (int i = 0; i < m; ++i) {
            cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        }

        absake(n, queries);
    }

    return 0;
}
