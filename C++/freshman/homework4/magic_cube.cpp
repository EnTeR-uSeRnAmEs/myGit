#include <bits/stdc++.h>
using namespace std;

int cube[51][51];
void rubikCube(int n)
{
    int k, i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cube[i][j] = 0;
    i = 0;
    j = n / 2;
    for (k = 1; k <= n * n; k++)
    {
        cube[i][j] = k;
        if (cube[(i - 1 + n) % n][(j + 1 + n) % n] == 0)
        {
            i = (i - 1 + n) % n;
            j = (j + 1 + n) % n;
        }
        else
            i = (i + 1 + n) % n;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << cube[i][j];
            if (j == n - 1) cout << endl;
            else cout << " ";
        }
    }
}

int main()
{
    int len, times = 1;
    while (cin >> len)
    {
        cout << "Case " << times++ << ":" << endl;
        rubikCube(len);
    }
    return 0;
}