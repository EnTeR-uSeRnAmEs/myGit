#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	return x % y == 0 ? y : gcd(y, x % y);
}

int main()
{
    int a, b;
    while (cin >> a >> b) cout << gcd(a, b) << endl;
    system("pause");
    return 0;
}