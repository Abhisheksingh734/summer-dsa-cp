#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{

    unordered_map<char, int> mp;
    for (auto x : s1)
    {
        mp[x]++;
    }

    int window = s1.size();

    int i = 0, j = 0;
    int count = mp.size();

    while (j < s2.size())
    {

        // calc
        if (mp.find(s2[j]) != mp.end())
        {
            mp[s2[j]]--;

            if (mp[s2[j]] == 0)
                count--;
        }

        if (j - i + 1 < window)
        {
            j++;
        }
        else if (j - i + 1 == window)
        {

            if (count == 0)
                return true;

            if (mp.find(s2[i]) != mp.end())
            {
                mp[s2[i]]++;

                if (mp[s2[i]] == 1)
                    count++;
            }

            i++;
            j++;
        }
    }

    return false;
}

string minWindow(string s, string t)
{
    unordered_map<char, int> mp;

    int minlen = INT_MAX;
    int start = 0;

    for (auto s : t)
    {
        mp[s]++;
    }

    int i = 0, j = 0;
    int count = mp.size();

    while (j < s.size())
    {
        // calc
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;

            if (mp[s[j]] == 0)
                count--;
        }

        if (count != 0)
        {
            j++;
        }
        else if (count == 0)
        {
            // window size reached

            // increment i while count ==0
            while (count == 0)
            {
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                        count++;
                }

                minlen = min(minlen, (int)(j - i + 1));
                start = i;
                // store potential ans

                i++;
            }
            j++;
        }
    }

    return minlen == INT_MAX ? "" : s.substr(start, minlen);
}

int main()
{
    string ans = minWindow("cabwefgewcwaefgcf", "cae");
    cout << ans;

    return 0;
}