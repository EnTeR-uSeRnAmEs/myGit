#include <iostream>
using namespace std;


double fun(double x)
{
    if (x >= 0 && x < 5) return -x + 2.5;
    else if (x >= 5 && x < 10) return 2 - 1.5 * (x - 3) * (x - 3);
    else if (x >= 10 && x < 20) return x / 2 - 1.5;
}

int main()
{
    double x;
    while (cin >> x) printf("%.3lf\n", fun(x));
    system("pause");
    return 0;
}