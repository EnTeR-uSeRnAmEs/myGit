#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len, times = 1, triangle[21][21];
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            triangle[i][j] = 1;
        }
    }
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (j == 0 || j == i)
                continue;
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    while (cin >> len)
    {
        // int triangle[len +1][len + 1] = {1};
        cout << "Case " << times++ << ":" << endl;
        for (int i = 0; i <= len; i++)
        {
            for (int j = 0; j <= len; j++)
            {
                cout << triangle[i][j];
                if (i == j)
                {
                    cout << endl;
                    break;
                }
                else
                    cout << " ";
            }
        }
    }

    system("pause");
    return 0;
}