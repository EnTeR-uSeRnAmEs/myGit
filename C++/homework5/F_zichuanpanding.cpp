#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases = 1;
    string key_str;
    while(getline(cin, key_str))
    {
        string str;
        int re = -1;
        getline(cin, str);
        re = str.find(key_str);
        cout << "Case " << cases++ << ": " << re << endl;
    }
    return 0;
}