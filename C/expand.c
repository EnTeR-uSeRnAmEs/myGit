#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char s[1000], k[1000];
	int i, t = 0;
	scanf("%s", s);
	t = i;
	for (i = 0; i <= strlen(s) - 1; i++)
	{
		if (s[i] == '-')
		{
			if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] < s[i + 1])
			{
				for (; k[t] <= s[i + 1]; t++)
				{
					k[t] = s[i - 1]++;
					k[t]++;
				}
			}
			else if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i - 1] < s[i + 1])
			{
				for (;; t++)
				{
					k[t] = s[i - 1]++;
					k[t]++;
					if (k[t] > s[i + 1])
						break;
				}
			}
			else if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z' && s[i - 1] < s[i + 1])
			{
				for (;; t++)
				{
					k[t] = s[i - 1]++;
					k[t]++;
					if (k[t] > s[i + 1])
						break;
				}
			}
			else
			{
				k[t] = '-';
				t++;
				i--;
			}
			i++;
		}
		else
		{
			k[t] = s[i];
			t++;
		}
	}
	k[t] = '\0';
	puts(k);
	system("pause");
	return 0;
}
