#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    string temp;
    int times = 1;
    while(getline(cin, temp))
    {
        int i = 0;
        stringstream ss;
        ss.str(temp);
        while (ss >> temp) i++;
        cout << "Case " << times++ << ": " << i << endl;
    }
    system("pause");
    return 0; 
}