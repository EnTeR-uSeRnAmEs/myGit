#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, year, month, day, i, sum;
    char e, f;
    while (cin >> year >> month >> day)
    {
        sum = 0;
        a[2] = 28;
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            a[2] = 29;
        for (i = 1; i < month; i++)
            sum = sum + a[i];
        cout << sum + day << endl;
    }
    system("pause");
    return 0;
}