#include <bits/stdc++.h>
using namespace std;

int d = 1, sum = 1, num;

void fenjie(int k)
{
    if (sum > num) return;
    else if (sum == num)d++;
    if (sum < num)
    {
        for (int i = k; i <= num; i++) 
        {
            sum *= i;
            fenjie(i);
            sum /= i;
        }
    }
}


void  fun(int a,int n)
{
	int i;
	for(i = a; i <= n; i++)
	{
		if(n % i == 0 && i * i <= n)
		{
			d++;
			fun(i,n / i);
		}
		if(i * i > n)	break;
	}
}

int main()
{
    int times;
    cin >> times;
    while(times)
    {
        cin >> num;
        // fenjie(2);
        fun(2, num);
        cout << d << endl;
        times--;
        d = 1;
    }
    return 0;
}