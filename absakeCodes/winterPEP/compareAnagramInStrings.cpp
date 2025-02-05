#include <bits/stdc++.h>
using namespace std;

void compareStringsForAnagram(string str, string pattern)
{

    unordered_map<char, int> patternMap;
    unordered_map<char, int> strMap;

    for (auto x : pattern)
    {
        patternMap[x]++;
    }

    int cnt = 0;

    int i = 0;
    int j = 0;

    while (j < str.size())
    {

        strMap[str[j]]++;

        if (strMap == patternMap)
        {
            cnt++;
        }

        if ((j - i + 1) == pattern.size())
        {
        }

        while ((j - i + 1) > pattern.size())
        {
            strMap[str[i]]--;
            if (strMap[str[i]] == 0)
            {
                strMap.erase(str[i]);
            }
            i++;
        }

        j++;
    }

    cout << cnt << endl;
}

bool canPlace(vector<int> arr, int B, int min)
{

    int bird = 1;
    int location = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        int curr_location = arr[i];

        if (curr_location - location >= min)
        {
            bird++;
            location = arr[i];
        }

        if (bird == B)
            return true;
    }

    return false;
}

void angryBirds(vector<int> arr, int N, int B)
{

    int start = 1;
    int end = arr[N - 1];

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (canPlace(arr, B, mid))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << end << " ";
}

int main()
{
    // compareStringsForAnagram("abcdbab", "ab");
    vector<int> arr = {1, 2, 4, 8, 9};

    angryBirds(arr, 5, 3);
}