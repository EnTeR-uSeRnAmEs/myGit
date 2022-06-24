#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    if (str[0] >= '0' && str[0] <= '9')
    {
        cout << "no" << endl;
        system("pause");
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == '_'))
        {
            cout << "no" << endl;
            system("pause");
            return 0;
        }
    }
    cout << "yes" << endl;
    system("pause");
    return 0;
}