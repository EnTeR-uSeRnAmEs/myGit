#include <bits/stdc++.h>
using namespace std;

int main()
{
    int times, cases = 1;
    while(cin >> times)
    {
        cin.ignore();
        while (times--)
        {
            string str, re = "";
            getline(cin, str);
            for (int i = 0; i < int(str.length()); i++)
            {
                re = str[i] + re;
            }
            cout << "Case " << cases++ << ": " << re << endl;
            // cout << str << endl;
        }
    }

    system("pause");
    return 0;
}