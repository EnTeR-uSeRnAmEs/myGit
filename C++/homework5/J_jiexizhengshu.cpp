#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    string temp, str[66000], re = "";
    int times = 1;
    while(getline(cin, temp))
    {
        int n = 0, len = 0;
        stringstream ss;
        ss.str(temp);
        while(ss >> str[n ++]);
        n --;
        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j < (int)str[i].length(); j++)
            {
                if (str[i][j] - 48 >= 0 && str[i][j] - 48 <=9)
                {
                    if ((j == 0) || !(str[i][j - 1] - 48 >= 0 && str[i][j - 1] - 48 <=9)) 
                    {
                        re += " ";
                        len++;
                    }
                    re += str[i][j];
                }
            }
        }
         
        cout << "Case " << times++ << ": (" << len << ")" << re << endl;
        re = "";
    }
    system("pause");
    return 0; 
}