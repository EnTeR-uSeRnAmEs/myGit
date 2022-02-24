#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    string temp, str[66000], re;
    int times = 1;
    while(getline(cin, temp))
    {
        int n = 0;
        stringstream ss;
        ss.str(temp);
        while(ss >> str[n ++]);
        n --;
        for (int i = 0; i <= n - 1; i++)
        {
            if(str[i].length() == 1)
                if(str[i][0] == 'a' || str[i][0] == 'A')
                    continue;   //ºöÂÔ"a"
            if(str[i].length() == 2)
            {
                if((str[i][0] == 'a' || str[i][0] == 'A') && (str[i][1] == 'n' || str[i][1] == 'N'))
                    continue;   //ºöÂÔ"an"
                if((str[i][0] == 'o' || str[i][0] == 'O') || (str[i][1] == 'f' || str[i][1] == 'F'))
                    continue;   //ºöÂÔ"of"
            }
            if(str[i].length() == 3)
            {
                if((str[i][0] == 'a' || str[i][0] == 'A') && (str[i][1] == 'n' || str[i][1] == 'N') && (str[i][2] == 'd' || str[i][2] == 'D'))
                    continue;   //ºöÂÔ"and"
                if((str[i][0] == 't' || str[i][0] == 'T') && (str[i][1] == 'h' || str[i][1] == 'H') && (str[i][2] == 'e' || str[i][2] == 'E'))
                    continue;   //ºöÂÔ"the"
                if((str[i][0] == 'f' || str[i][0] == 'F') && (str[i][1] == 'o' || str[i][1] == 'O') && (str[i][2] == 'r' || str[i][2] == 'R'))
                    continue;   //ºöÂÔ"for"
            }
            re += str[i][0];
            for(int j = 0; j <= (int)str[i].length(); j++)
                if(str[i][j] == '-')
                    re += str[i][j+1];
        }
        cout << "Case " << times++ << ": " << re << endl;
        re = "";
    }
    system("pause");
    return 0; 
}