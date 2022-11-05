#include <bits/stdc++.h>
using namespace std;

int main()
{
    string T, R;
    int flag = 0;
    cin >> T >> R;
    for (int i = 0; i < int(T.size()); i++)
    {
        if (T[i] == R[i])
            flag++;
        else
            break;
    }
    for (int i = 0; i < int(T.size()); i++)
    {
        if (T[T.size() - i] == R[R.size() - i])
            flag++;
        else
            break;
    }
    if (flag >= int(T.size()))
        cout << "YES";
    else
        cout << "NO";
    // return 0;
    system("pause");
}