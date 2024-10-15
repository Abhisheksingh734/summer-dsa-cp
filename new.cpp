#include <bits/stdc++.h>
using namespace std;

int dividesArray(vector<int> arr, int start, int end)
{

    int sum = 0;
    for (auto it : arr)
    {
        sum += it;
    }

    int target = sum / 2;
    // base cond

    if (arr.size() < 2)
        return 0;

    int currSum = 0;
    int left = 0;
    int right = 0;
    for (int i = start; i < end; i++)
    {

        currSum += arr[i];

        if (currSum == target)
        {
            left = dividesArray(arr, start, i) + 1;
            right = dividesArray(arr, i + 1, end) + 1;
        }
    }

    return left + right;
}

// int main()
// {
//     vector<int> arr = {4, 1, 1, 0, 1, 0, 1};
//     // {4} --
//     // 110 101 --
//     // {1} {10} {1} {01}

//     // if sum %2 ==0
//     // loop
//     int numOfsubArrays = divideArray(arr, 0, arr.size());

//     cout << numOfsubArrays << endl;
// }

//        {4, 1, 1, 0, 1, 0, 1} --1
//    {4}             {1, 1, 0, 1, 0, 1}  --2
//    X          {1, 1, 0,} --3        {1, 0, 1} --4
//            {1}    {1,0}            {1}    {0,1}

// { 0 , 0, 0 ,0 ,2}

// stetp 1 -> take sum of arr till it equals to totalSum /2 (targetSum)
// step 2 -> divide array in two parts left nd right

// arr size < 2

int divideArray(vector<int> &arr, int start, int end)
{

    int sum = 0;
    for (auto it : arr)
    {
        sum += it;
    }

    // base cndtion
    if (sum % 2 != 0 || arr.size() < 2)
        return 0;

    int left = 0;
    int right = 0;

    int targetSum = sum / 2;
    int currSum = 0;
    for (int i = start; i < end; i++)
    {

        // if sum exceeds the target sum ???

        currSum += arr[i];
        if (currSum == targetSum)
        {
            // divide the array
            left = divideArray(arr, start, i) + 1;
            // if (i < arr.size())
            right = divideArray(arr, i + 1, end) + 1;

            return left + right;
        }
        else if (currSum > targetSum)
            return 0;
    }
}

int main()
{

    vector<int> arr = {4, 0, 1, 1, 4};
    int numberofDivisions = divideArray(arr, 0, arr.size());

    cout << numberofDivisions << endl;
}