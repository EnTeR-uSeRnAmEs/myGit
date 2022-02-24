#include <bits/stdc++.h>
using namespace std;

long long FenJieZhiYinShu(long long num1, long long num2)
{
    long long num1_factor[100]{}, num2_factor[100]{}, array1 = 0, array2 = 0, re = 1;
    if (num1 < 1 || num2 < 1) return 0;
    for (int i = 2; i <= num1; i++)
    {
        if(num1 % i == 0)
        {
            num1_factor[array1++] = i;
            num1 /= i;
            i = 1;
        }
    }
    for (int i = 2; i <= num2; i++)
    {
        if(num2 % i == 0)
        {
            num2_factor[array2++] = i;
            num2 /= i;
            i = 1;
        }
    }
    if (array1 > array2)
    {
        for (int i = 0; i < array2; i++) 
        {
            long long *tmp = find(num1_factor, num1_factor + array1, num2_factor[i]) ;
            if (*tmp != 0)
            {
                re *= *tmp;
                *tmp = 0;
            }
        }
    } 
    else 
    {
        for (int i = 0; i < array1; i++) 
        {
            long long *tmp = find(num2_factor, num2_factor + array2, num1_factor[i]) ;
            if (*tmp != 0)
            {
                re *= *tmp;
                *tmp = 0;
            }
        }
    }
    return re;
}

int main()
{
    long long num1, num2;
    while (cin >> num1 >> num2) 
    {
        long long tmp = FenJieZhiYinShu(num1, num2);
        if (tmp) cout << tmp << endl;
        else cout << "无最大公因数！" << endl;
    }
    return 0;
}