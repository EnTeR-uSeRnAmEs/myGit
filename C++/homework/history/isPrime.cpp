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
