#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n) 
{
    int i;
    if (n <= 1) return false;
    for(i = 2; i <= sqrt(n); i++) 
    {
        if((n % i) == 0) return false;
    }
    return true;
}

int main()
{
    int num;
    cin >> num;
    for (int num1 = 2; num1 < num; num1++) 
    {
        if (isPrime(num1)) 
        {
            for (int num2 = num1; num2 < num; num2++) 
            {
                int num3;
                num3 = num - num1 - num2;
                if (isPrime(num2) && isPrime(num3))
                {
                    cout << num1 << " " << num2 << " " << num3 << endl;
                    system("pause");
                    return 0;
                } 
            }
        }
    }
}