#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases = 1;
    string str, re = "";
    while (getline(cin, str))
    {
        for (int i = 0; i < int(str.length()); i++)
        {
            if (str[i] < 0 && str[i + 1] < 0)
            {
                re = str[i + 1] + re;
                re = str[i] + re;
                i++;
            }
            else re = str[i] + re;
        }
        cout << "Case " << cases++ << ": \"" << re << "\"" << endl;
        re = "";
    }

    system("pause");
    return 0;
}