#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        // for (int i = 0; i < line.length(); i++)
        while(1)
        {
            if (line[0] == ' ' || line[0] == '\t') line.erase(0, 1);
            else break;
        }
        for (int i = line.length() - 1; i > 0; --i) 
        {
            if (line[i] == ' ' || line[i] == '\t') line.erase(i, 2);
            else break;
        }
        cout << line << endl;
    }
    system("pause");
    return 0;
}
