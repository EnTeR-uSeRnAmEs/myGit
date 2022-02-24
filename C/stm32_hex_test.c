#include <stdio.h>
#include <math.h>
// int main()
// {
//     char s[50];
//     scanf("%s", s);
//     int t = strlen(s);
//     long sum = 0;
//     for (int i = 0; i < t; i++)
//     {
//         if (s[i] >= 'a' && s[i] <= 'z')
//             s[i] = (int)(s[i] - 'a') + 10 + '0';
//         sum += ((s[i] - '0') * (pow(16, t - 1 - i)));
//     }
//     printf("%ld\n", sum);
// }

int H_to_D(char a)
{
	int n;
	if(a >= '0' && a <= '9')n = a - '0';
	else n = a - 'a' + 10;	
	return n;
}

int main()
{
    while(1)
    {
        char s[50];
        scanf("%s", s);
        printf("%ld\n", H_to_D(s));
    }
}