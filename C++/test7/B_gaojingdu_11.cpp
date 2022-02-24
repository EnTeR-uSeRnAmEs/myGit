#include <bits/stdc++.h>
using namespace std;

int main()
{
    string longnumber;
    while (cin >> longnumber)
    {
        long sum1 = 0, sum2 = 0;
        for (int i = 0; i < (int)longnumber.size(); i++)
        {
            
            if (longnumber[i] >= '0' && longnumber[i] <= '9')
            {
                if (i % 2 == 0) sum1 += (int)longnumber[i] - 48;
                else if (i % 2 == 1) sum2 += (int)longnumber[i] - 48;
            }
        }
        if ((sum1 - sum2) % 11 == 0) cout << "Y" << endl;
        else cout << "N" <<endl;
    }
    return 0;
}