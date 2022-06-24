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
            string str, re = "Yes";
            getline(cin, str);
            for (int i = 0; i < int(str.length() / 2); i++)
            {
                if (str[i] != str[str.length() - i - 1]) 
                {
                    re = "No";
                    break;
                }
            }
            cout << "Case " << cases++ << ": " << re << endl;
            // cout << str << endl;
        }
    }

    system("pause");
    return 0;
}