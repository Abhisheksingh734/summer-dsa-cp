#include <bits/stdc++.h>
using namespace std;

using ll = long long;

long long
aPowerb(long long a, long long b)
{
    if (b == 0)
        return 1;

    return a * aPowerb(a, b - 1);
}

long long aPowb(long long a, int n)
{
    long long res = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            res *= a;
        }
        n = n / 2;
        a *= a;
    }

    return res;
}

long long aPowbRecursive(long long a, int n)
{
    if (n == 0)
        return 1;

    long long temp = aPowbRecursive(a, n / 2);

    if (n & 1)
    {
        temp = temp * temp * a;
    }
    else
    {
        temp = temp * temp;
    }

    return temp;
}

int main()
{
    long long a = 2;
    long long b = 3;
    cout << aPowbRecursive(a, b) << endl;
}