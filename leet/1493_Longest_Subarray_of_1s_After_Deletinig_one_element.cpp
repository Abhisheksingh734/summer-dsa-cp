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