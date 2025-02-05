
#include <bits/stdc++.h>
using namespace std;

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

bool canDivide(vector<int> coins, int k, int min)
{
    int partition = 0;

    int sum = 0;

    for (int i = 0; i < coins.size(); i++)
    {

        if (sum + coins[i] >= min)
        {

            partition++;
            sum = 0;
        }
        else
        {
            sum += coins[i];
        }

        if (partition == k)
            return true;
    }

    return false;
}

void GameOfGreed(vector<int> arr, int k)
{
    int start = *min_element(arr.begin(), arr.end());

    int end = accumulate(arr.begin(), arr.end(), 0);
    int result = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (canDivide(arr, k, mid))
        {
            result = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << result << endl;
}

int main()
{
    // compareStringsForAnagram("abcdbab", "ab");
    // vector<int> arr = {1, 2, 4, 8, 9};
    // angryBirds(arr, 5, 3);

    vector<int> coins = {1, 2, 3, 4, 5, 6};
    GameOfGreed(coins, 3);
}