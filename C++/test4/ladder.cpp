#include <iostream>
using namespace std;

int fun(int len)
{
    if (len == 1) return 1;
    else if (len == 2) return 2;
    return fun(len - 2) + fun(len - 1);
}

int main()
{
    int num;
    while (cin >> num)
    {
        cout << fun(num) << endl;
    }
    return 0;
}