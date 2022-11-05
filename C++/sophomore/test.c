#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 81

int main()
{
    char str[N];
    int i, sum = 0, count = 0;
    printf("Enter a string:");
    gets(str);
    for (i = strlen(str); i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            sum += (str[i] - '0') * pow(10.0, count++);
        }
    }
    sum *= 2;
    printf("digit=");
    for (count = 0; sum / (int)pow(10.0, count); count++)
        ;
    for (i = count; i > 0;)
    {
        printf("%d", sum / (int)pow(10.0, --i));
        sum %= (int)pow(10.0, i);
        if (i % 3 == 0 && i != 0)
            printf(",");
    }
    printf("\n");
    system("pause");
    return 0;
}