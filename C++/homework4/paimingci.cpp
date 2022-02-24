#include <bits/stdc++.h>
using namespace std;

int Read_In(double *nums)
{
    double tmp;
    int len = 0;
    while(cin >> tmp)
    {
        *(nums + len) = tmp;
        len++;
        if (cin.peek() == '\n') break;
    }
    return len;
}

void pmc(double *nums, int len)
{
    int rank;
    for (int i = 0; i < len; i++)
    {
        rank = 1;
        for (int j = 0; j < len; j++)
        {
            if (nums[i] < nums[j])
                rank++;
        }
        if (i < len - 1)
            cout << rank << ", ";
        else
            cout << rank << endl;
    }
}

int main()
{
    double nums[1000];
    int times = 1;
    while (cin.peek() != EOF)
    {
        int len = Read_In(nums);
        cout << "Case " << times++ << ":" << endl;
        pmc(nums, len);
    }
    system("pause");
    return 0;
}



/*
#include <iostream>
using namespace std;
int main()
{
    double a[1000];
    int rank, n = 0, num = 1;
    while (cin >> a[0])
    {
        n = 1;
        while (cin.peek() != '\n')
        {
            cin >> a[n];
            n++;
        }
        cout << "Case " << num++ << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            rank = 1;
            for (int j = 0; j < n; j++)
            {
                if (a[i] < a[j])
                    rank++;
            }
            if (i < n - 1)
                cout << rank << ", ";
            else
                cout << rank << endl;
        }
    }
    return 0;
}
*/