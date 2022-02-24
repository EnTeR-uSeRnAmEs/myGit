#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    double r, m, y;
    cin >> r >> m >> y;
    r = 1 + r / 100;
    cout << int(m * pow(r, y)) << endl;
    system("pause");
    return 0;
}