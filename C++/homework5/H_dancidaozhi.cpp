#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    string str[66000], temp;
    int times = 1;
    while(getline(cin, temp))
    {
        stringstream ss;
        int i = 0;
        ss << temp;
        while (ss >> str[i++]);
        cout << "Case " << times++ << ":";
        if (str[0] == "") cout << " " << endl;
        else
        {
            for (i -= 2; i >= 0; --i)
            {
                cout << " " << str[i];
                if (!i) cout << endl;
            }
        }
        str[0] = "";
        
    }
    system("pause");
    return 0; 
}