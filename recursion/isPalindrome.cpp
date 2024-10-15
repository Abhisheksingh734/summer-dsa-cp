#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &arr, int start, int end)
{
    if (start > end)
        return true;

    if (arr[start] == arr[end])
    {
        if (check(arr, start + 1, end - 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    vector<int> arr = {2, 4, 7, 7, 4, 2};
    if (check(arr, 0, 5))
    {
        cout << "is Palindrome";
    }
    else
    {
        cout << "Not a Palindrome";
    }
}