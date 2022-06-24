#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int row, col, k = 0;
    double x, sum;

    while (getline(cin, str))
    {
        istringstream istr(str);
        sum = 0;
        for(col = 0; istr >> x; col++) sum += x;
        for (row = 1; getline(cin, str); row++)
        {
            if (str.length() == 0) break;
            istringstream istr1(str);
            while(istr1 >> x) sum += x;
        }
        cout << "Case " << ++k << ": " << row << ", " << col << ", " << sum << endl;
    }
    system("pause");
    return 0;
}