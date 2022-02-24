#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    while(cin >> x >> y)
    {
        int max, d1[1000] = {0}, d2[1000] = {0};
        for (int i = 1, j = 0; i <= x; i++)
        {
            if (x % i == 0)
            {
                // cout << i << " ";
                d1[j++] = i;
            }
        }
        // cout << endl;
        for (int i = 1, j = 0; i <= y; i++)
        {
            if (y % i == 0)
            {
                // cout << i << " ";
                d2[j++] = i;
            }
        }
        for (int i = 0; d1[i] != 0; i++)
        {
            for (int j = 0; d2[j] != 0; j++)
            {
                if (d1[i] == d2[j]) max = d2[j];
            }
        }
        cout << max << endl;
    }
}