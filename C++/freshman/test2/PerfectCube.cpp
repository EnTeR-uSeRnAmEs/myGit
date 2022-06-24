#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, a, b, c, d;
    cin >> n;
    for (a = 2; a <= n; a++)
    {
        for (b = 2; b <= n; b++)
        {
            for (c = b; c <= n; c++)
            {
                for (d = c; d <= n; d++)
                {
                    if (a * a * a == b * b * b + c * c * c + d * d * d)
                    {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}