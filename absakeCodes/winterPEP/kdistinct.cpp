#include <bits/stdc++.h>
using namespace std;

void kdistinct(string s, int k)
{

    unordered_map<char, int> mp;

    int i = 0;
    int j = 0;
    int maxy = 0;

    while (j < s.size())
    {
        mp[s[j]]++;

        if (mp.size() > k)
        {
            while (mp.size() != k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
        }

        if (mp.size() <= k)
            maxy = max(maxy, j - i + 1);
        j++;
    }

    cout << maxy;
}

int main()
{
    string s = "abbaccd";
    kdistinct(s, 2);
}