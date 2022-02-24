#include <bits/stdc++.h>

int main()
{
    int times, num, tmp;
    scanf("%d", &times);
    while(times--)//yysy我在这里喜欢用for
    {
        bool flag = false;
        scanf("%d", &num);
        tmp = num;
        if(num % 7 == 0) flag = true;
        else
        {
            while(tmp != 0)
            {
                if(tmp % 10 == 7) 
                {
                    flag = true;
                    break;
                }
                else tmp /= 10;
            }
        }
        if(flag) printf("pa\n");
        else printf("%d\n", num);
    }
    return 0;
}