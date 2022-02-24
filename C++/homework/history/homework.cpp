#include <algorithm>
#include <iostream>
using namespace std;

int isPrime(int n) 
{
    int i;
    for(i = 2; i <= sqrt(n); i++) {
        if((n % i) == 0)
            return 0;
    }
    return 1;
}


int main()
{
    int a, num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> a;
        for (int j = 2; j <= (sqrt(num) + 1); j++)
        {
            if (isPrime(j) && !isPrime(a))
            {
                if (a % j == 0)
                {}
            }
        }
    }
}