#include <bits/stdc++.h>
using namespace std;

int main()
{
    int init;
    while (cin >> init)
    {
        int sum = 0;
        while (init != 1)
        {
            sum++;
            if (init % 2) init = 3 * init + 1;
            else init /= 2;
        }
        cout << sum << endl;
    }
    system("pause");
    return 0;
}
