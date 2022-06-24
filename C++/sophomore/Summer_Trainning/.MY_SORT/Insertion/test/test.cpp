#include <bits/stdc++.h>
using namespace std;

#define NUM 20

template <typename T>
int memcmp(T dest, T source, int len)
{
    if (dest < source)
        return 1;
    else if (dest > source)
        return -1;
    else
        return 0;
}

int main()
{
    const int a = 1, b = 2;
    char c[] = {"abc"}, d[] = {"dab"};
    cout << memcmp(a, b, sizeof(int)) << " " << memcmp(c, d, sizeof(c)) << endl;
    system("pause");
    return 0;
}