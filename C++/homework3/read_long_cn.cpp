#include <iostream>
#include <math.h>

using namespace std;

string _N[] = {"", "Ò¼", "·¡", "Èþ", "ËÁ", "Îé", "Â½", "Æâ", "°Æ", "¾Á",}, _P[] = {"", "Ê°", "°Û", "Çª",}, _Q[] = {"","Íò","ÒÚ","Õ×","¾©",};

void format_end(string x, int num)
{
    cout << "Case " << num << ": " << x << endl;
}

int length(long num)
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

string _conv(long long num)
{
    string r;
    if(num<0) return "¸º" + _conv(-num);
    if(num<10) return _N[num];
    short len = (short)length(num);
    long long p10 = (long long)pow(10, len);
    if(len<4) r = _N[num/p10] + _P[len];
    else
    {
        p10 /= pow(10,len-len/4*4);
        r = _conv(num/p10) + _Q[len/4];
    }
    if (num % p10 < p10 / 10 && num % p10 > 0)
        r += "Áã";
    return r + _conv(num % p10);
}

string conv(long long num) { return num ? _conv(num) : "Áã"; }

int main()
{
    long long a;
    int case_num = 1;
    while (cin >> a)
        format_end(conv(a), case_num++);
    return 0;
}