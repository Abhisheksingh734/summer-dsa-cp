#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    int i = 0;
    int j = 0;
    vector<int> freq(26, 0); // array, size= 26 with all init val = 0; , store freq at char index
    int maxcnt = 0;
    int ans = 0;
    while (j < s.size())
    {

        freq[s[j] - 'A']++;
        maxcnt = *max_element(freq.begin(), freq.end());

        while ((j - i + 1) - maxcnt > k)
        {
            freq[s[i] - 'A']--;
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans; 
}

int main()
{
    string s = "AABABBA";

    int k = 1;

    cout << characterReplacement(s, k);
}