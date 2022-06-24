#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y)
{
    if (x < 1 || y < 1) return 0;
    vector <long long> vct1, vct2;
    long long max;
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0){vct1.push_back(i);}
    }
    for (int i = 1; i <= y; i++)
    {
        if (y % i == 0){vct2.push_back(i);}
    }
    for (int i = 0; vct1[i] != 0; i++)
    {
        vector <long long> :: iterator it = find(vct2.begin(),vct2.end(),vct1[i]);
        if (it != vct2.end()) max = vct1[i];
    }
    return max;
}

int main()
{
    long long x, y;
    while(cin >> x >> y)
    {
        long long tmp = gcd(x, y);
        if (tmp) cout << tmp << endl;
        else cout << "无最大公因数！" << endl;
    }
}