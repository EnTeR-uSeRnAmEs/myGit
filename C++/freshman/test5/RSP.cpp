#include <bits/stdc++.h>
using namespace std;

int change(string *s)
{   int ans;
    if (*s == "Rock") ans = 0;
    else if (*s == "Scissors") ans = 1;
    else if (*s == "Paper") ans = 2;
    return ans;
}

int main()
{
    int times, a1, a2;
    cin >> times;
    while(times) 
    {
        times--;
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == "Rock") a1 = 0;
        else if (s1 == "Scissors") a1 = 1;
        else if (s1 == "Paper") a1 = 2;
        if (s2 == "Rock") a2 = 0;
        else if (s2 == "Scissors") a2 = 1;
        else if (s2 == "Paper") a2 = 2;
        if (a1 - a2 == 0) cout << "Tie" << endl;
        else if (a1 - a2 == -1 || a1 - a2 == 2) cout << "Player1" << endl;
        else if (a1 - a2 == 1 || a1 - a2 == -2) cout << "Player2" << endl;

    }

    system("pause");
    return 0;
}