#include <bits/stdc++.h>
using namespace std;

int main()
{
    string longnumber;
    while (cin >> longnumber)
    {
        // bool sign = 1;
        long sum = 0;
        for (int i = 0; i < (int)longnumber.size(); i++)
        {
            if (longnumber[i] == '.') 
            {
                sum = -1;
                break;
            }
            else if (longnumber[i] >= '0' && longnumber[i] <= '9')
            {
                sum += (int)longnumber[i] - 48;
            }
        }
        if (sum % 3 == 0) cout << "Y" << endl;
        else cout << "N" <<endl;
    }
    return 0;
}