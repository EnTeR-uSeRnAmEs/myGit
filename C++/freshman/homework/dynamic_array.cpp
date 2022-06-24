#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y);

int main()
{
    vector <int> a1(0), a2(0);
    for (int i = 0; i < 10; i++)
    {
        a1.push_back(i);
    }
    a1.erase(a1.begin() + 4);
    int num = 0;
    for (int i = 0; i < a1.size(); i++)
    {
        cout << a1[i] << " ";
        num++;
    }
    cout << endl << num << endl;
    // vector<int>::iterator it = find(a1.begin(), a1.end(), 3);
    // cout << *it << endl;
    system("pause");
}

// int gcd(int x, int y) {return (x % y == 0) ? y : gcd(y, x % y);}

