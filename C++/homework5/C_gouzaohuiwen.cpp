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
            if (int(str.length()) % 2 == 0)
                for (int i = 0; i < int(str.length()); i++) re = str[i] + re;
            else 
                for (int i = 0; i < int(str.length()) - 1; i++) re = str[i] + re;
            re = str + re;
            cout << "Case " << cases++ << ": \"" << re << "\""<< endl;
        }
    }
    system("pause");
    return 0;
}