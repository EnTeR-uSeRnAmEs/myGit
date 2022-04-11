#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *p1, const void *p2)
{
    char *a = (char *)p1;
    char *b = (char *)p2;
    return strcmp(a, b) > 0 ? 1 : -1;
}

int main()
{
    char s[1000][100] = {"\0"}, tmp_str[100] = {"\0"};
    int i = -1, count = 1;
    FILE *fp = fopen("article.txt", "r");
    fscanf(fp, "%s", s[++i]);
    strlwr(s[i]);
    int len = strlen(s[i]);
    if (s[i][len - 1] == ',' || s[i][len - 1] == '.' || s[i][len - 1] == ';')
        s[i][len - 1] = '\0';
    while (fscanf(fp, " %s", s[++i]) != EOF)
    {
        strlwr(s[i]);
        int len = strlen(s[i]);
        if (s[i][len - 1] == ',' || s[i][len - 1] == '.' || s[i][len - 1] == ';')
            s[i][len - 1] = '\0';
    }
    len = i;
    qsort(s, len, sizeof(s[0]), cmp);
    strcpy(tmp_str, s[0]);
    for (i = 1; i <= len + 1; ++i)
    {
        if (strcmp(tmp_str, s[i]) == 0)
            ++count;
        else
        {
            printf("%s %d\n", tmp_str, count);
            strcpy(tmp_str, s[i]);
            count = 1;
        }
    }
    system("pause");
    return 0;
}