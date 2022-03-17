#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char in[100], out[100];
    char str[1000], c;
    int count = 0, i = 0;
    FILE *fp1 = fopen("filein.txt", "r");
    FILE *fp2 = fopen("fileout.txt", "w");
    scanf("%s", in);
    scanf("%s", out);

    while (!feof(fp1))
    {
        int start, flag = 0;
        c = fgetc(fp1);
        for (i = 0; i < strlen(in); ++i)
        {
            if (c == toupper(in[i]) || c == tolower(in[i]))
            {
                if (flag == 0) {start = count;}
                flag = 1;
            }
            else {break;}
        }
        str[count++] = c;
        if (flag == 1 && i == strlen(in))
        {
            for (i = 0; i < strlen(out); ++i) {str[start + i] = out[i];}
            flag = 0;
            count += i - 1;
        }
    }
    str[--count] = '\0';
    // printf("%s\n", str);
    fputs(str, fp2);
    fclose(fp1);
    fclose(fp2);
    // system("pause");
    return 0;
}