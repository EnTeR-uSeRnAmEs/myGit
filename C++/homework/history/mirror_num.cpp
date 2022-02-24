#include <iostream>
#include <math.h>
using namespace std;

int is_mirror(int n)
{
    int x = 0;
    int s = n; // 拷贝一份
    while (s > 0)
    {
        x = x * 10 + s % 10;
        s = s / 10;
    }
    if (x == n)
    {
        cout << "YES!" << endl;
        return 1;
    }
    else
    {
        cout << "NO!" << endl;
        return 0;
    }
}

int main() 
{
    int T, i;
    cin >> T;
    for (T = 0; cin >> i; T--)
    {;
    }
    system("pause");
    return 0;
}