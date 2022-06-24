#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len, a[55][55], times = 1;
    while (cin >> len)
    {
        for (int k = 1; k <= (len + 1) / 2; k++)
        {
            for (int i = k; i <= len + 1 - k; i++)
            {
                for (int j = k; j <= len + 1 - k; j++) a[i][j] = k;
            }
        }
        cout << "Case " << times++ << ":" << endl;
        for (int i = 1; i <= len; i++)
        {
            for (int j = 1; j < len; j++)
                cout << a[i][j] << " ";
            cout << a[i][len] << endl;
        }
    }

    system("pause");
    return 0;
}