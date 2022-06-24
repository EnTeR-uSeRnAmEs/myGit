#include <iostream>
using namespace std;

void format_end(string x, int num)
{
    cout << "Case " << num << ": " << x << endl;
}

int count(long num)
{
    int output = 0;
    if (num == 0) return 1;
    while (num > 0)
    {
        num /= 10;
        output++;
    }
    return output;
}

string change(long num)
{
    string str = "";
    long num_tmp = num;
    int temp = 0, co = count(num_tmp), flag = 1;
    for (int i = 0; i < co; i++)
    {
        temp = num_tmp % 10;
        string chnum = "ÁãÒ¼·¡ÈşËÁÎéÂ½Æâ°Æ¾Á", chdigit1 = "Ê°°ÛÇª";
        // if (chnum.substr(temp * 2, 2) == "Áã") flag = 0;
        // else flag = 1;
        str = chnum.substr(temp * 2, 2) + str;
        if (i < co - 1) str = chdigit1.substr(i * 2, 2) + str;
        num_tmp /= 10;
    }
    return str;
}

string all_lj(long num)
{
    string str = "";
    if (num == 0) return "Áã";
    for (int i = 0; num != 0; i++)
    {
        int temp = num % 10000;
        num /= 10000;
        str = change(temp) + str;
        if (i == 0 && num != 0)
            str = "Íò" + str;
        else if (i == 1 && num != 0)
            str = "ÒÚ" + str;
    }
    return str;
}

string reset(string num)
{
    if (num.substr((int)num.size() - 2) == "Áã") num.erase(num.size() - 2);
    return num;
}

int main()
{
    long long num = 0, case_num = 1;
    while (cin >> num) format_end(reset(all_lj(num)), case_num++);
    return 0;
}
