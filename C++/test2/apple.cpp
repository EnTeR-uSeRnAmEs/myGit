#include <iostream>
using namespace std;


int count(int m,int n)
{
   if(n == 1 || m == 0)  return 1;
   if(m < n) return count(m, m);
   else return count(m, n - 1) + count(m - n, n);
}

int main()
{
    int num, m, n;
    cin >> num;
    while (num && cin >> m >> n) 
    {
        num--;
        cout << count(m, m) << endl;
    }
    system("pause");
    return 0;
}