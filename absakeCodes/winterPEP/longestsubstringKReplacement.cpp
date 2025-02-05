#include <bits/stdc++.h>
using namespace std;

void longestSubstringWithKReplacement(string s, int k)
{

    vector<int> freq(26, 0);

    int i = 0;
    int j = 0;

    int maxCnt = 0;
    while (j < s.size())
    {

        freq[s[j] - 'a']++;

        int maxy = *max_element(freq.begin(), freq.end());

        while ((j - i + 1) - maxy > k)
        {
            freq[s[i] - 'a']--;
            i++;
        }

        maxCnt = max(maxCnt, j - i + 1);
        j++;
    }

    cout << maxCnt << " ";
}

int main()
{
    longestSubstringWithKReplacement("aabbacab", 2);
}