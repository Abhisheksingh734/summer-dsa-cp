#include <bits/stdc++.h>
using namespace std;

void longestSubstring(string str)
{
    unordered_map<char, int> mp;

    int i = 0, j = 0;
    int maxy = 0;

    while (j < str.size())
    {
        // check if char is already persent in map
        if (mp.find(str[j]) != mp.end())
        {

            while (str[i] != str[j])
            {
                mp.erase(str[i]);
                i++;
            }
            i++;
        }
        else
        {
            mp[str[j]]++;
        }

        maxy = max(maxy, j - i + 1);

        j++;
    }

    cout << maxy << endl;
}

int main()
{
    longestSubstring("abcdaefghexyzg");
}

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> map = {{0, 1}};
        int pSum = 0;
        int res = 0;

        int i = 0;

        while (i < nums.size())
        {
            pSum += nums[i];

            int diff = pSum - k;
            if (map.find(diff) != map.end())
            {
                res += map[diff];
            }
            map[pSum]++;

            i++;
        }

        return res;
    }
};