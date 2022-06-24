#include <iostream>
#include <math.h>
using namespace std;

int isPrime(int n) 
{
    int i;
    for(i = 2; i <= sqrt(n*1.0); i++) 
     {
        if((n % i) == 0)
            return 0;
    }
    return 1;
}

int is_mirror(int n)
{
    int x = 0;
    int s = n;
    while (s > 0)
    {
        x = x * 10 + s % 10;
        s = s / 10;
    }
    if (x == n) return 1;
    else return 0;
}

int GetLen(int x)
{
    int num=0;
    while(x){num++;x/=10;}
    return num;
}

int reverse(int n)
{
    int x = 0, s = n;
    while (s > 0)
    {
        x = x * 10 + s % 10;
        s /= 10;
    }
    return x;
}

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    num2 /= pow(10.0, GetLen(num2) / 2);
    for (int i = num1; i <= num2; i++)
    {
        if (is_mirror(i) && isPrime(i)) cout << i << endl;
    }
    system("pause");
    return 0;
}