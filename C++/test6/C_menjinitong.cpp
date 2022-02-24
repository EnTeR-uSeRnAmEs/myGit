#include <iostream>
using namespace std;

int main()
{
    int len;
    while (cin >> len)
    {
        int visitors[1000], tmp, i = 0;
        bool change[1000] = {1};
        while (cin >> tmp)
        {
            visitors[i++] = tmp;
            if (i == len) 
            {
                i = 0;
                break;
            }
        }
        for (int i = 0; i < len; i++)
        {
            int times = 1;
            if (change[i])
            {
                int tmp1 = visitors[i];
                visitors[i] = times;
                for (int j = i + 1; j < len; j++)
                {
                    if (visitors[j] == tmp1 && change[j])
                    {
                        change[j] = 0;
                        visitors[i] = (++i);
                    }
                }
            }
        }
        for (int i = 0; i < len; i++)
        {
            cout << visitors[i] << " ";
        }
    }

    system("pause");
    return 0;
}