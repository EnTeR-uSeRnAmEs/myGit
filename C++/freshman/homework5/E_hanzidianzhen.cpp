#include <bits/stdc++.h>
using namespace std;

bool judging(int8_t ucData, int8_t intFlag)
{
    int8_t ucFlag;
    switch (intFlag)
    {
        case 1:
        {
            ucFlag = 0x01;
            break;
        }
        case 2:
        {
            ucFlag = 0x02;
            break;
        }
        case 3:
        {
            ucFlag = 0x04;
            break;
        }
        case 4:
        {
            ucFlag = 0x08;
            break;
        }
        case 5:
        {
            ucFlag = 0x10;
            break;
        }
        case 6:
        {
            ucFlag = 0x20;
            break;
        }
        case 7:
        {
            ucFlag = 0x40;
            break;
        }
        case 8:
        {
            ucFlag = 0x80;
            break;
        }
    }
    ucData &= ucFlag;
	if (0x00 == ucData)
		return false;
	else if (ucData == ucFlag)
		return true;
}

int main() 
{ 
    int temp1, temp2, times = 1, i = 0;
    while(cin >> hex >> temp1 >> hex >> temp2)//0x80
    {
        string re = "";
        for (int i = 8; i > 0; --i)
        {
            if (judging(temp1, i)) re += "¡ö";
            else re += "¡õ";
        }
        for (int i = 8; i > 0; --i)
        {
            if (judging(temp2, i)) re += "¡ö";
            else re += "¡õ";
        }
        if (i == 32) i = 0;
        if (i == 0) cout << "Case " << times++ << ":" << endl;
        i += 2;
        cout << re << endl;
    }
    system("pause");
    return 0; 
}