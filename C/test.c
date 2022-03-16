#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char in[100], out[100];
    int i = 0;
    FILE *fp1 = fopen("filein.txt", "r");
    FILE *fp2 = fopen("fileout.txt", "w");
    scanf("%s", in);
    scanf("%s", out);
    for (i = 0; i < strlen(in); i++)
    {
        in[i] = tolower(in[i]);
    }
    fgetc(fp1);
    strcpy(in, out);
    // fputc(char, fp1);

}