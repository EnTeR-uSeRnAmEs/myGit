#include <iostream>
using namespace std;

int main()
{
    double num = 0, sum = 0, max, min,flag = 1;
    double tmp;
    while(scanf("%lf", &tmp) != EOF) 
    {
        // cin >> tmp;
        if (flag == 1)
        {
            max = tmp;
            min = tmp;
            flag = 0;
        }
        sum += tmp;
        if (tmp > max){max = tmp;}
        if (tmp < min){min = tmp;}
        num++;
    }
    cout << num << ", " << min << ", " << max << ", " << (sum - min - max)/(num-2) << endl;
    return 0;
}