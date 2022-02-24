#include <bits/stdc++.h>
using namespace std;

int main()
{
    string longnumber1, longnumber2;
    while (cin >> longnumber1 >> longnumber2)
    {
        bool sign1 = true, sign2 = true;
        if (longnumber1[0] == '-') 
        {
            longnumber1.erase(0,1);
            sign1 = false;
        }
        if (longnumber2[0] == '-') 
        {
            longnumber2.erase(0,1);
            sign2 = false;
        }
        longnumber1 = '0' + longnumber1;
        int j = (int)longnumber1.size() - 1;
        for (int i = (int)longnumber2.size() - 1; i >= 0; --i)
        {
            if (sign1 == sign2)
            {
                int tmp = (int)longnumber1[j] + (int)longnumber2[i] - 48 * 2;
                if (tmp / 10)
                {
                    longnumber1[j - 1]++;
                    tmp %= 10;
                }
                longnumber1[j] = tmp + 48;
            }
            else if (sign1 != sign2)
            {
                int tmp = (int)longnumber1[j] - (int)longnumber2[i];
                if (tmp < 0)
                {
                    int tmp2 = j;
                    while (longnumber1[--tmp2] == '0') longnumber1[tmp2] = '9';
                    longnumber1[tmp2]--;
                    tmp = 10 + tmp;
                }
                longnumber1[j] = tmp + 48;
            }
            --j;
        }
        while (longnumber1[0] == '0') longnumber1.erase(0,1);
        if (longnumber1 == "") longnumber1 = "0";
        if (!sign1 && longnumber1 != "0") longnumber1 = '-' + longnumber1;
        cout << longnumber1 << endl;
    }
    return 0;
}