#include <bits/stdc++.h>
using namespace std;

string bases = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int num, base, tmp, times = 1;
    while (cin >> num >> base)
    {
        string output = "";
        while (num / base != 0)
        {
            tmp = num % base;
            num /= base;
            output = bases[tmp] + output;
        }
        tmp = num % base;
        num /= base;
        output = bases[tmp] + output;
        cout << "Case " << times++ << ": " << output << endl;
    }
}