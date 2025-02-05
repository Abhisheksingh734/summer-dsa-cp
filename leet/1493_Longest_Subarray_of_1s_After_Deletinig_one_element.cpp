#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int i = 0;
    int j = 0;

    bool zero = false;
    unordered_map<int, int> mp;
    int maxy = 0;
    while (j < nums.size())
    {

        if (nums[j] == 0)
            zero = true;

        if (nums[j] == 0 && mp[nums[j]] == 1)
        {

            maxy = max(maxy, mp[1]);

            while (nums[i] != 0)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            mp[nums[i]]--;
            i++;
        }

        mp[nums[j]]++;
        j++;
        maxy = max(maxy, mp[1]);
    }
    if (zero)
        return maxy;

    return maxy - 1;
}

int main()
{
}


class Solution {
public:
    #define MOD 1000000007

     long long modInverse(long long A, long long M) {
        long long res = 1;
        long long exp = M - 2;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * A) % M;
            }
            A = (A * A) % M;
            exp /= 2;
        }
        return res;
    }

    long long fact(long long n) {
        vector<long long> factorial(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = (i * factorial[i - 1]) %MOD;
        }

        return factorial[n];
    }

    // long long countDup(string str) {
    //     unordered_map<char, int> mp;
    //     for (auto x : str) {
    //         mp[x]++;
    //     }
    //     long long dup = 1;
    //     for (auto i : mp) {
    //         if (i.second > 1) {
    //             dup = (dup * fact(i.second)) % MOD;
    //         }
    //     }

    //     return dup;
    // }
    vector<long long> countDup(string str) {
        unordered_map<char, int> mp;
        for (auto x : str) {
            mp[x]++;
        }
        vector<long long> dup;
        for (auto i : mp) {
            if (i.second > 1) {
                 dup.push_back((fact(i.second)) % MOD);
            }
        }

        return dup;
    }

    int countAnagrams(string s) {
        int i = 0;
        string str = "";
        long long res = 1;
        while (i <= s.size()) {
            if (i == s.size() || s[i] == ' ') {
                if (str.size() == 0) {
                    i++;
                    continue;
                }
                long long len = str.size();
                long long ftc = fact(len);
                ftc = ftc % MOD;

                vector<long long> fctdup = countDup(str);

                // long long div;

                for(auto it: fctdup){
                    ftc = (ftc *( modInverse(it, MOD) + MOD)) % MOD;
                }

                res = (res * ftc) % MOD;
                str = "";
            } else {
                str += s[i];
            }
            i++;
        }

        return res;
    }
};