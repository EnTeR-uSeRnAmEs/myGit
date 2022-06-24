#include <iostream>
using namespace std;

int main()
{
    int len;
    while (cin >> len)
    {
        int sum = 0;
        int nums[1000], tmp, i = 0;
        while (cin >> tmp)
        {
            nums[i++] = tmp;
            if (i == len) 
            {
                i = 0;
                break;
            }
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (nums[j] - nums[i] == 1 || nums[j] - nums[i] == -1) sum++;
            }
        }
        cout << sum << endl;
    }
    system("pause");
    return 0;
}