#include "String.h"
#include <malloc.h>
#include <cstring>

String::String(const char *s)
{
    fitmem(s);
}

String::String(const String &Str)
{
    fitmem(Str.str);
}

String::String(const char c, int n)
{
    int i;
    if (n < 0)
        n = 0;
    char temp[n + 1];
    for (i = 0; i < n; i++)
        temp[i] = c;
    temp[i] = '\0';
    fitmem(temp);
}

String::String(const String &Str, int pos, int n)
{
    int m = strlen(Str.str);
    if (m == 0)
    {
        fitmem("");
        return;
    }
    if (pos >= m || pos < -m)
        pos = m - 1;
    else if (pos < 0 && pos > -m)
        pos = m + pos;
    if ((n > 0 && pos + n >= m) || n == 0) //
        n = m - pos;
    else if (n < 0)
        n = 1;
    char temp[n + 1];
    temp[n] = '\0';
    for (int i = 0; i < n; i++)
        temp[i] = Str.str[pos + i];
    fitmem(temp);
}

String::~String()
{
    if (str != NULL)
    {
        delete[] str;
        str = NULL;
    }
}

bool String::empty()
{
    return (strlen((*this).str) == 0);
}

int String::length() const
{
    return strlen(str);
}

int String::capacity() const
{
    return _msize(str);
}

String String::substr(int pos, int n) const
{
    String temp(*this, pos, n);
    return temp;
}

const char *String::c_str()
{
    return str;
}

String &String::insert(int pos, const String &Str)
{
    int len = strlen(str);
    if (pos > len)
        pos = len;
    if (pos < 0)
        pos = 0;
    char tmp[len + strlen(Str.str) + 1];
    strncpy(tmp, str, pos);
    tmp[pos] = '\0';
    strcat(tmp, Str.str);
    strcat(tmp, str + pos);
    fitmem(tmp);
    return *this;
}

int String::find(const String &Str) const
{
    int i, j, m, n, flag;
    m = strlen(Str.str);
    n = strlen(str);
    if (m > n)
        return -1;
    for (i = 0; i < n - m; i++)
    {
        flag = 1;
        for (j = 0; j < m; j++)
            if (str[i + j] != Str.str[j])
            {
                flag = 0;
                break;
            }
        if (flag == 1)
            return i;
    }
    return -1;
}

String &String::replace(int pos, int n, const String &Str)
{
    String temp = *this;
    temp = temp.erase(pos, n);
    temp = temp.insert(pos, Str);
    fitmem(temp.str);
    return *this;
}

String &String::erase(int pos, int n)
{
    int len = strlen(str);
    if (pos > len)
        pos = len;
    if (n == 0 || pos + n > len)
        n = len - pos;
    if (n < 0)
        return *this;
    str[pos] = '\0';
    strcat(str, str + pos + n);
    fitmem(str);
    return *this;
}

String &String::trim()
{
    int i, j = strlen(str);
    char *temp = (char *)"";
    if (j == 0)
        return *this;
    for (j--; j >= 0 && (str[j] == ' ' || str[j] == '\t'); j--)
        ;
    str[j + 1] = '\0';
    for (i = 0; str[i] == ' ' || str[i] == '\t'; i++)
        ;
    if (i > j)
    {
        fitmem(temp);
    }
    else
    {
        temp = new char[j - i + 2];
        strcpy(temp, str + i);
        fitmem(temp);
        delete[] temp;
    }
    return *this;
}

String &String::operator+=(const String &Str)
{
    *this = *this + Str;
    return *this;
}

char &String::operator[](int index)
{
    if (index >= 0 && index < length())
        return str[index];
    else if (index < 0 && index > -1 - length())
        return str[length() + index];
    return str[length()];
}

String &String::operator=(const String &Str)
{
    if (&Str == this)
        return *this;
    fitmem(Str.str);
    return *this;
}

String operator+(const String &Str1, const String &Str2)
{
    String temp;
    temp.str = new char[strlen(Str1.str) + strlen(Str2.str) + 1];
    strcpy(temp.str, Str1.str);
    strcat(temp.str, Str2.str);
    return temp;
}

bool operator==(const String &Str1, const String &Str2)
{
    return strcmp(Str1.str, Str2.str) == 0;
}

bool operator!=(const String &Str1, const String &Str2)
{
    return strcmp(Str1.str, Str2.str) != 0;
}

bool operator>(const String &Str1, const String &Str2)
{
    return (strcmp(Str1.str, Str2.str) > 0);
}

bool operator>=(const String &Str1, const String &Str2)
{
    return (strcmp(Str1.str, Str2.str) >= 0);
}

bool operator<(const String &Str1, const String &Str2)
{
    return (strcmp(Str1.str, Str2.str) < 0);
}

bool operator<=(const String &Str1, const String &Str2)
{
    return (strcmp(Str1.str, Str2.str) <= 0);
}

ostream &operator<<(ostream &out, const String &Str)
{
    out << Str.str;
    return out;
}

istream &operator>>(istream &in, String &Str)
{
    char tmp;
    int i = 0;
    char temp[100];
    temp[0] = '\0';
    Str = "";
    while (true)
    {
        tmp = in.get();
        if (tmp == '\n' || tmp == ' ')
        {
            Str = Str + temp;
            break;
        }
        temp[i++] = tmp;
        temp[i] = '\0';
        if (i == 99)
        {
            Str = Str + temp;
            i = 0;
            temp[i] = '\0';
        }
    }
    return in;
}

void String::fitmem(const char *s)
{
    char tmp[strlen(s) + 1];
    strcpy(tmp, s);
    if (_msize(str) <= strlen(tmp) || _msize(str) > (strlen(tmp) + 1) * 3)
    {
        delete[] str;
        str = new char[2 * (strlen(tmp) + 1)];
    }
    strcpy(str, tmp);
    return;
}

void String::fitmem(char *s)
{
    if (_msize(str) <= strlen(s) || _msize(str) > (strlen(s) + 1) * 3)
    {
        if (s != str)
        {
            delete[] str;
            str = new char[2 * (strlen(s) + 1)];
            strcpy(str, s);
        }
        else
        {
            char tmp[strlen(s) + 1];
            strcpy(tmp, s);
            delete[] str;
            str = new char[2 * (strlen(tmp) + 1)];
            strcpy(str, tmp);
        }
    }
    else
        strcpy(str, s);
    return;
}