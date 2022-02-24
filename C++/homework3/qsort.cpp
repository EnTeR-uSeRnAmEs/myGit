#include <bits/stdc++.h>
using namespace std;

int inc(const void *a, const void *b)
{
	return *(double *)a > *(double *)b? 1 : -1;
 } 

int main()
{
    int tmp, num = 0, cases = 1;
    double a[100000] = {0};
    // vector<int> a;
    while (cin >> tmp)
    {
        a[num ++] = tmp;
        if (cin.peek() == '\n') 
        {
            qsort(a, num, sizeof(double), inc);
            cout << "Case " << cases++ << ": ";
            for (int i = 0; i < num; i++) 
            {
                if (i != num - 1) cout << a[i] << " ";
                else cout << a[i] << "\n";
            }
            num = 0;
        }
    }
    return 0;  
}