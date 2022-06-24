#include <bits/stdc++.h>
using namespace std;

long long cnm(int n,int m)
{
    long long s = 1;
    int k = 1;
    if(m > n/2)
        m = n-m;
    for(int i=n-m+1;i<=n;i++)
    {
        s *= (long long)i;
        while(k<=m && s%k == 0)
        {
            s /= (long long)k;
            k++;
        }
    }
    return s;
}

int main()
{
    int m, n, times = 1;
    while (cin >> n >> m) cout << "Case " << times++ << ":" << '\n' << cnm(n, m) << endl;
    system("pause");
    return 0;
}