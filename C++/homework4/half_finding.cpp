#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nums[1000], numf, tmp, back_data, times = 1, flag;
    while (cin >> numf)
    {
        int len_start = 0, len = 0;
        while (cin >> tmp)
        {
            nums[len++] = tmp;
            if (cin.peek() == '\n') break;
        }
        len--;
        while(true)
        {
            int mid = (len_start + len) / 2;
            if (nums[mid] == numf) 
            {
                back_data = mid;
                flag = 0; 
                break;
            }
            else if (nums[mid] < numf) len_start = mid;
            else if (nums[mid] > numf) len = mid;
            if (len - len_start <= 1) 
            {
                if (numf == nums[len]) 
                {
                    back_data = len;
                    flag = 2;
                    break;
                }
                else if (numf == nums[len_start])
                {
                    back_data = len_start;
                    flag = 2;
                    break;
                }
                else
                {
                    back_data = -1;
                    flag = 3;
                    break;
                }
            }
        }
        cout << "Case " << times++ << ": " << numf << ", " << back_data << "  " << flag << endl;
        // for (int i = 0; i < len; i++) cout << nums[i] << ' ';
        // cout << endl;
    }

    system("pause");
    return 0;
}