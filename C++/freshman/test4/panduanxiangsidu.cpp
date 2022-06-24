#include <bits/stdc++.h>
using namespace std;

int main()
{
    int temp, wide, length, num = 0;
    vector <int> s1, s2;
    cin >> wide >> length;
    for (int i = 0; i < length * wide; i++)
    {
        cin >> temp;
        s1.push_back(temp);
    }
    for (int i = 0; i < length * wide; i++)
    {
        cin >> temp;
        s2.push_back(temp);
    }
    for (int i = 0; i < length * wide; i++)
    {
        if (s1[i] == s2[i]) num++;
    }
    double out = double(num) / (wide * length * 1.0) * 100;
    printf("%.2lf\n",out);
    system("pause");
    return 0;
}