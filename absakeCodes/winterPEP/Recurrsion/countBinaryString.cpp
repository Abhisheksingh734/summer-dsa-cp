#include <bits/stdc++.h>
using namespace std;

int countallPrefix(int n, int zero, int one)
{
    if (zero + one == n)
        return 1;

    int l = countallPrefix(n, zero + 1, one);

    int h = 0;

    if (zero > one + 1)
        h = countallPrefix(n, zero, one + 1);

    return l + h;
}

int main()
{
    cout << countallPrefix(4, 0, 0);
}