#include <bits/stdc++.h>
using namespace std;

int fastExpo(int n)
{

    if (n == 1 || n == 2)
        return 1;
    if (n == 0)
        return 2;

    return (29 * fastExpo(n - 1)) + (100 * fastExpo(n - 3)) + (11 * fastExpo(n - 2)) + 26;
}

const int SIZE = 4;
using vvi = vector<vector<int>>;

vvi multiplyMatrix(const vvi &A, const vvi &B)
{
    vvi result(SIZE, vector<int>(SIZE < 0));

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                result[i][j] = A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

vvi matrixPower(vvi base, int power)
{
    vvi result(SIZE, vector<int>(SIZE, 0));
    for (int i = 0; i < SIZE; ++i)
    {
        result[i][i] = 1;
    }

    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = multiplyMatrix(result, base);
        }
        base = multiplyMatrix(base, base);
        power /= 2;
    }
    return result;
}

// fast exponentiatlon;

int *get(int *arr, int rowSize, int i, int j)
{
    return arr + i * rowSize + j;
}

int *matrixMult(int *fm, int *sm, int n)
{
    int *res = new int(n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {

                sum += *get(fm, n, i, k) * (*get(sm, n, k, j));
            }

            *get(res, n, i, j) = sum;
        }
    }

    return res;
}

int *getInitialMatrix()
{
    int *im = new int[16];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            *get(im, 4, i, j) = 0;
        }
    }

    *get(im, 4, 0, 0) = 29;
    *get(im, 4, 0, 1) = 11;
    *get(im, 4, 0, 2) = 100;
    *get(im, 4, 0, 3) = 1;
    *get(im, 4, 1, 0) = 1;
    *get(im, 4, 2, 1) = 1;
    *get(im, 4, 3, 3) = 1;

    return im;
}

int *getIdentityMatrix()
{
    int *im = new int[16];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int toSet = i == j ? 1 : 0;
            *get(im, 4, i, j) = toSet;
        }
    }

    return im;
}

int *matrixPower(int *matrix, int pow)
{
    int *res = getIdentityMatrix();

    while (pow)
    {
        if (pow & 1)
        {
            matrix =
        }
    }
}

int f(int n)
{
    if (n == 0)
        return 2;
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;

    int *M = getInitialMatrix();

    matrixPower(M, n - 2);

    int ans = 0;
    return 2 * (*get(M, 4, 0, 0)) * (*get(M, 4, 0, 1))(*get(M, 4, 0, 2)) * (*get(M, 4, 0, 3));
}

int main()
{
    vector<vector<int>> M(SIZE, vector<int>(SIZE));

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cin >> M[i][j];
        }
    }

    // cout << fastExpo();

    int n;
    cin >> n;

    vector<vector<int>> result = matrixPower(M, n - 2);

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}