#include <bits/stdc++.h>
using namespace std;

vector <int> prime(int x);
bool isPrime(int n);

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

vector <int> prime(int x)
{   
    x = double(x);
    vector <int> result(0);
    for (int i = 2; i <= x; i++)
    {
        if (isPrime(i) && x % i == 0)
        {
            result.push_back(i);
            x /= i;
        }
    }
    return result;
}

int main()
{
    int a;
    vector <int> a_prime(0);
    
    while (cin >> a)
    {
        a_prime = prime(a);
        cout << a_prime.size();
        for (int i = 0; i < int(a_prime.size()); i++)
        {
            cout << a_prime[i] << " ";
        }
        cout << endl;
    }
}