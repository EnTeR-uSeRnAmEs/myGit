#include <stdio.h>
#include <windows.h>

int main()
{
    int VUL, D, t, i;
    while (scanf("%d %d", &VUL, &D) == 2)
    {
        if (VUL <= D) t = 1;
        else if (VUL > D)
        {
            t = 0;
            i = 1; 
            while(1)
            {
                VUL -= D * i;
                t += i;
                t++;
                i++;
                if (VUL <= i * D)
                {
                    t += VUL / D;
                    if (VUL % D) t++;
                    break;
                }
            }
        }
        printf("%d\n", t);
    }
    system("pause");
    return 0;
}