#include <bits/stdc++.h>
using namespace std;

int dec2hex(int dec)
{
    map<int, string> mmap = {{0, "0"}, {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}, {10, "a"}, {11, "b"}, {12, "c"}, {13, "d"}, {14, "e"}, {15, "f"}};
    string result = "";
    int flag = 0, re = 0;
    while (dec != 0)
    {
        // if (!flag)
        result = mmap[dec % 16] + result;
        // else
        //     result += 9 * pow(10, i++);
        dec /= 16;
    }
    for (int j = 0; j < int(result.length()); j++)
    {
        if (result[j] > '9')
            flag = 1;
        if (!flag)
            re = re * 10 + result[j] - '0';
        else
            re = re * 10 + 9;
    }
    return re;
}

int main()
{
    int t;

    // while (true)
    // {
    //     cin >> t;
    //     cout << dec2hex(t) << endl;
    // }

    cin >> t;
    while (t--)
    {
        int l, r, lnums = 0, rnums = 0, x;
        cin >> l >> r;
        lnums = dec2hex(l);
        rnums = dec2hex(r);
        while (l)
        {
            if (l % 16 >= 10)
            {
                x = 0;
                break;
            }
            else
                x = 1;
            l /= 16;
        }
        cout << rnums - lnums + x << endl;
        cout << lnums << " " << rnums << " " << x << endl;
    }
    // return 0;
    system("pause");
}