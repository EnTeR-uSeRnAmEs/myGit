#include <iostream>
#include <math.h>
using namespace std;
int result = 1, counts = 1;
int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int gcd_bb(int a, int b)
{
    int result_tmp = gcd(a, b);
    if (result_tmp != 1)
    {
        if (counts > b)
        {
            return result;
        }
        else
        {
            a = a / result_tmp;
            counts++;
            result *= result_tmp;
            gcd_bb(a, b);
        }
    }
    else
    {
        return result;
    }
}

int main()
{
    double a, b;
    while (cin >> a >> b)
    {
        result = 1;
        counts = 1;
        cout << gcd_bb(a, b) << endl;
    }
    return 0;
}