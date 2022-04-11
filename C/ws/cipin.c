#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word
{
	int num;
	char s[100];
} Word;

int cmp(const void *p1, const void *p2)
{
	struct word *a = (struct word *)p1;
	struct word *b = (struct word *)p2;
	return strcmp(a->s, b->s);
}

int main()
{
	Word op[100];
	int i = 0, j, k = 1, t = 0, cnt = 0;
	char a[100] = {}, b[100] = {};
	FILE *fp = fopen("article.txt", "r");
	while (fgets(a, 99, fp) != NULL)
	{
		while (a[i])
		{
			if (a[i] >= 'A' && a[i] <= 'Z')
			{
				b[cnt] = 'a' + a[i] - 'A';
				cnt++;
			}
			else if ((a[i] >= 'a' && a[i] <= 'z') || a[i] == ' ' || a[i] == '\n')
			{
				b[cnt] = a[i];
				cnt++;
			}
			++i;
			char a[100] = {};
		}
	}
	for (i = 0; i < cnt; i++)
	{
		printf("%c", b[i]);
	}
	for (i = 0; i < cnt; i++)
	{
		if (b[i] >= 'a' && b[i] <= 'z')
		{
			op[t].s[0] = b[i];
			k = 1;
			for (j = i + 1; j < cnt; j++)
			{
				if (b[j] == ' ')
				{
					op[t].num = 1;
					break;
				}
				else
				{
					op[t].s[k] = b[j];
					k++;
				}
			}
		}
	}
	for (i = 0; i < t; i++)
	{
		for (j = i + 1; j < t; j++)
		{
			if (op[i].s == op[j].s)
			{
				op[i].num++;
				op[j].s[0] = '*';
			}
		}
	}
	qsort(op, t, sizeof(Word), cmp);
	for (i = 0; i < t; i++)
	{
		if (op[i].s[0] != '*')
		{
			printf("%s %d\n", op[i].s, op[i].num);
		}
	}
	system("pause");
	return 0;
}
