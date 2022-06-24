#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    string temp;
    while(getline(cin, temp))
    {
        if (temp[0] % 2 == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    system("pause");
    return 0; 
}