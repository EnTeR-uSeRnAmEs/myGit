#include <bits/stdc++.h>
using namespace std;

int main()
{
    int days;
    while (cin >> days) 
    {
        int exdays1, exdays2;
        exdays1 = (days / 5);
        if (days % 5 <= 3) exdays2 = days % 5;
        else exdays2 = days % 5 - 2;
        cout << exdays1 + exdays2 << endl;
    }

    system("pause");
    return 0;
}
