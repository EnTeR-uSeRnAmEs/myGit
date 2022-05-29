#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unordered_map.h"

char *findRepeatedDnaSequences(char *s)
{
    char ans[1001];
    unsigned int map_size = 1000, L;
    unordered_map_t *cnt = new_unordered_map(map_size);
    int n = len(s);
    for (int i = 0; i <= n - L; ++i)
    {
        string sub = s.substr(i, L);
        if (++cnt[sub] == 2)
        {
            ans.push_back(sub);
        }
    }
    return ans;
}