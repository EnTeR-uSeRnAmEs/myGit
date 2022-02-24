#include <iostream>
using namespace std;

int gcd_jianfa(int x, int y)
{
    if (x == y) return x;
    else if (x > y) return gcd_jianfa(x - y, y);
    else if (x < y) return gcd_jianfa(x, y - x);
}

int main()
{
    int x, y;
    while(cin >> x >> y)
    {
        cout << gcd_jianfa(x, y) << endl;
    }
}