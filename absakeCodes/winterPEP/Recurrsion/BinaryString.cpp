#include <bits/stdc++.h>
using namespace std;

int noOfwaysBinaryString(int prev, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (prev != 1)
    {
        return noOfwaysBinaryString(0, n - 1) + noOfwaysBinaryString(1, n - 1);
    }
    else
    {
        return noOfwaysBinaryString(0, n - 1);
    }
}

int main()
{

    int n = 5;
    cout << noOfwaysBinaryString(0, n - 1) + noOfwaysBinaryString(1, n - 1);
}
