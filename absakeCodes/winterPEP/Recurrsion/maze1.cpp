#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int maze1(int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }

    int r = 0, d = 0;

    if (i < m - 1)
        d = maze1(i + 1, j, m, n);

    if (j < n - 1)
        r = maze1(i, j + 1, m, n);

    return r + d;
}

int main()
{
    cout << maze1(0, 0, 3, 3);
}