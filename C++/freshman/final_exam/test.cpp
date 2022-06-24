#include <bits/stdc++.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <string.h>

using namespace std;

int main()
{
    int x = 42;
    auto f = [&x]{
        return x;
    };
    x = 0;
    auto y = f();
    cout << y << endl;
    system("pause");
    return 0;
}