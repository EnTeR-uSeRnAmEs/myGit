#include <bits/stdc++.h>
using namespace std;

int main()
{
    int monthd, dayd, yeard, times = 1, month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string months, days, years;
    while (cin >> yeard >> monthd >> dayd)
    {
        int day_num = 0, flag = 0;
        if (yeard % 100 == 0) 
        {
            if (yeard % 400 == 0) flag = 1;
        }
        else if (yeard % 4 == 0) flag = 1;
        for (int i = 0; i < monthd - 1; i++) day_num += month_days[i];
        day_num += dayd;
        if (flag && monthd > 2) day_num++;
        months = to_string(monthd);
        days = to_string(dayd);
        years = to_string(yeard);
        if (months.length() == 1) months = '0' + months;
        if (days.length() == 1) days = '0' + days;
        for (; years.length() < 4; ) years = '0' + years;
        // printf("Case %d: %s/%s/%s, %d\n", times++, months, days, years, day_num);
        cout << "Case " << times++ << ": " << months << "/" << days << "/" << years << ", " << day_num << endl;
        // cout << flag << endl;
    }
    system("pause");
    return 0;
}