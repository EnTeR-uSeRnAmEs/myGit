#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len, wid, sum = 0;
    cin >> wid >> len;
    int mtx[len][wid];
    for (int i = 0; i < len; i++) 
    {
        for (int j = 0; j < wid; j++) 
        {
            cin >> mtx[i][j];
            if (i == 0 || j == 0 || i == len - 1 || j == wid - 1)
            {
                sum += mtx[i][j];
            }
        }
    }
    cout << sum << endl;
    system("pause");
    return 0;
}