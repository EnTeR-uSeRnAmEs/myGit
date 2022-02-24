#include <bits/stdc++.h>
using namespace std;

// int f(int n, int m)
// {
//     return n == 1 ? n : (f(n - 1, m) + m - 1) % n + 1;
// }

int main()
{
    int nums, members, times = 1;
    while (cin >> nums >> members)
    {
        int f = 0;
        for (int i = 1; i <= nums; i++) f = (f + members) % i;
        printf("Case %d: %d, %d, %d\n", times++, nums, members, f + 1);
    }
    system("pause");
    return 0;
}