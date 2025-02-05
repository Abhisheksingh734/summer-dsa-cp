#include <bits/stdc++.h>
using namespace std;

void compareStringsForAnagram(string str, string pattern)
{
    unordered_map<char, int> patternMap;
    unordered_map<char, int> strMap;

    vector<int> arr;

    for (auto x : pattern)
        patternMap[x]++;

    int cnt = 0;
    int i = 0, j = 0;

    while (j < str.size())
    {
        strMap[str[j]]++;

        if (j - i + 1 == pattern.size())
        {
            if (strMap == patternMap)
            {
                arr.push_back(i);
                cnt++;
            }

            strMap[str[i]]--;
            if (strMap[str[i]] == 0)
                strMap.erase(str[i]);
            i++;
        }

        j++;
    }

    for (auto x : arr)
    {
        cout << str.substr(x, pattern.size()) << " " << x << endl;
    }

    cout << cnt << endl;
}

int main()
{
    compareStringsForAnagram("abcdbab", "ab");
}
