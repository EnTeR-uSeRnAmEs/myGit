#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num_tmp, num1, num2, num3, sum = 0;
    char num4;
    while (cin.peek() != EOF)
    {
        scanf("%d-%d-%d-%c", &num1, &num2, &num3, &num4);
        num_tmp = num1 * 100000000 + num2 * 100000 + num3;
        for (int i = 0; i < 9; i++)
        {
            sum += (num_tmp % 10) * (9-i);
            num_tmp /= 10;
        }
        if (sum % 11 == (int)num4 - 48 || (num4 == 'X' && sum % 11 == 10)) cout << "Right" << endl;
        else if (sum % 11 == 10 && num4 != 'X') printf("%d-%d-%d-X\n", num1, num2, num3);
        else if (sum % 11 != (int)num4 - 48) printf("%d-%d-%d-%d\n", num1, num2, num3, sum % 11);
        sum = 0;
    }
    
    system("pause");
    return 0;
}