#include <bits/stdc++.h>
using namespace std;

double a[20];
int nums = 0;

double f(double x)
{
    double sum = 0;
    for (int i = 0; i < nums; i++) {sum += a[nums - i - 1] * pow(x, i * 1.0);}
    return sum;
}

double dichotomy(double a = 0, double b = 1)
{
    double x, x1 = a, x2 = b;
    while(x2 - x1 >= 1e-8)
    {
        x = (x1 + x2) / 2;
        cout << x1 << "  " << x2 << endl;
        if (f(x) * f(x2) <= 0) x1 = x;
        if (f(x1) * f(x) <= 0) x2 = x;
    }
    return x;
    
}

int main()
{
    double tmp, num = 1;
    while (cin >> tmp)
    {
        a[nums++] = tmp;
        if (cin.peek() == '\n')
        {
            cout << "Case " << num++ << ": " << dichotomy() << endl;
            //cout << f(2) << endl;
            nums = 0;
        } 

    }
    system("pause");
    return 0;
}