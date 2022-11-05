#ifndef __MY_STRING
#define __MY_STRING
#include <iostream>
#include <cstring>
#include <malloc.h>
#include "base.h"
using namespace std;

class ERROR
{
private:
    int type = -1; // 1:out of range
public:
    ERROR(int n) { type = n; }
    ERROR(const ERROR &a)
    {
        type = a.type;
    }
    void print()
    {
        if (type == 1)
        {
            cout << "Out of range!";
            return;
        }
        if (type == 2)
        {
            cout << "Illegal value!";
            return;
        }
        cout << "Unknown error!";
        return;
    }
};

class String : public base<char>
{
public:
    String(const char *s = "");

    String(const String &str);

    String(const char c, int n = 1) throw(ERROR);

    String(const String &Str, int pos, int n = 0) throw(ERROR);

    virtual ~String();

    virtual bool empty();

    int getlength() const;

    String substr(int pos, int n = 0) const;

    const char *c_str();

    String &insert(int pos, const String &Str) throw(ERROR);

    int find(const String &Str) const;

    String &replace(int pos, int n, const String &Str);

    String &erase(int pos, int n = 0) throw(ERROR);

    String &trim();

    String &operator+=(const String &Str);

    virtual char &operator[](int index) throw(ERROR);

    String &operator=(const String &Str);

    friend String operator+(const String &Str1, const String &Str2);
    friend bool operator==(const String &Str1, const String &Str2);
    friend bool operator!=(const String &Str1, const String &Str2);
    friend bool operator>(const String &Str1, const String &Str2);
    friend bool operator>=(const String &Str1, const String &Str2);
    friend bool operator<(const String &Str1, const String &Str2);
    friend bool operator<=(const String &Str1, const String &Str2);

    friend ostream &operator<<(ostream &out, const String &Str);
    friend istream &operator>>(istream &in, String &Str);

    virtual void fitmem(char *s);
    virtual void fitmem(const char *s);

private:
    void init();
    // char *str = NULL;
    // unsigned int _capacity = 0;
};

#endif
String::String(const char *s)
{
    init();
    fitmem(s);
}

String::String(const String &Str)
{
    init();
    fitmem(Str.data);
}

String::String(const char c, int n) throw(ERROR)
{
    init();
    if (n < 0)
        throw ERROR(2);
    int i;
    if (n < 0)
        n = 0;
    char temp[n + 1];
    for (i = 0; i < n; i++)
        temp[i] = c;
    temp[i] = '\0';
    fitmem(temp);
}

String::String(const String &Str, int pos, int n) throw(ERROR)
{
    init();
    int m = strlen(Str.data);
    if (m == 0)
    {
        fitmem("");
        return;
    }
    if (pos >= m || pos < -m || n < 0 || pos + n >= m)
        throw ERROR(1);
    if (pos < 0 && pos > -m)
        pos = m + pos;
    if (n == 0)
        n = m - pos;
    char temp[n + 1];
    temp[n] = '\0';
    for (int i = 0; i < n; i++)
        temp[i] = Str.data[pos + i];
    fitmem(temp);
}

String::~String()
{
    if (data != NULL)
    {
        delete[] data;
        data = NULL;
    }
}

bool String::empty()
{
    return (strlen((*this).data) == 0);
}

int String::getlength() const
{
    return strlen(data);
}

// int String::capacity() const
// {
//     return _capacity;
// }

String String::substr(int pos, int n) const
{
    String temp(*this, pos, n);
    return temp;
}

const char *String::c_str()
{
    return data;
}

String &String::insert(int pos, const String &Str) throw(ERROR)
{
    int len = strlen(data);
    if (pos > len || pos < 0)
        throw ERROR(1);
    char tmp[len + strlen(Str.data) + 1];
    strncpy(tmp, data, pos);
    tmp[pos] = '\0';
    strcat(tmp, Str.data);
    strcat(tmp, data + pos);
    fitmem(tmp);
    return *this;
}

int String::find(const String &Str) const
{
    int i, j, m, n, flag;
    m = strlen(Str.data);
    n = strlen(data);
    if (m > n)
        return -1;
    for (i = 0; i < n - m; i++)
    {
        flag = 1;
        for (j = 0; j < m; j++)
            if (data[i + j] != Str.data[j])
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
    fitmem(temp.data);
    return *this;
}

String &String::erase(int pos, int n) throw(ERROR)
{
    int len = strlen(data);
    if (pos > len || pos + n > len || n < 0)
        throw ERROR(1);
    if (n == 0)
        n = len - pos;
    if (n < 0)
        return *this;
    data[pos] = '\0';
    strcat(data, data + pos + n);
    fitmem(data);
    return *this;
}

String &String::trim()
{
    int i, j = strlen(data);
    if (j == 0)
        return *this;
    for (j--; j >= 0 && (data[j] == ' ' || data[j] == '\t'); j--)
        ;
    data[j + 1] = '\0';
    for (i = 0; data[i] == ' ' || data[i] == '\t'; i++)
        ;
    if (i > j)
    {
        fitmem("");
    }
    else
    {
        char temp[j - i + 2];
        strcpy(temp, data + i);
        fitmem(temp);
    }
    return *this;
}

String &String::operator+=(const String &Str)
{
    *this = *this + Str;
    return *this;
}

char &String::operator[](int index) throw(ERROR)
{
    if (index >= getlength() || index <= -1 - getlength())
        throw ERROR(1);
    if (index >= 0 && index < getlength())
        return data[index];
    else if (index < 0 && index > -1 - getlength())
        return data[getlength() + index];
    return data[getlength()];
}

String &String::operator=(const String &Str)
{
    if (&Str == this)
        return *this;
    fitmem(Str.data);
    return *this;
}

String operator+(const String &Str1, const String &Str2)
{
    String ans;
    char temp[strlen(Str1.data) + strlen(Str2.data) + 1];
    strcpy(temp, Str1.data);
    strcat(temp, Str2.data);
    ans.fitmem(temp);
    return ans;
}

bool operator==(const String &Str1, const String &Str2)
{
    return strcmp(Str1.data, Str2.data) == 0;
}

bool operator!=(const String &Str1, const String &Str2)
{
    return strcmp(Str1.data, Str2.data) != 0;
}

bool operator>(const String &Str1, const String &Str2)
{
    return (strcmp(Str1.data, Str2.data) > 0);
}

bool operator>=(const String &Str1, const String &Str2)
{
    return (strcmp(Str1.data, Str2.data) >= 0);
}

bool operator<(const String &Str1, const String &Str2)
{
    return (strcmp(Str1.data, Str2.data) < 0);
}

bool operator<=(const String &Str1, const String &Str2)
{
    return (strcmp(Str1.data, Str2.data) <= 0);
}

ostream &operator<<(ostream &out, const String &Str)
{
    out << Str.data;
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
    if (_capacity <= (int)strlen(tmp) || _capacity > (int)(strlen(tmp) + 1) * 3)
    {
        delete[] data;
        data = new char[2 * (strlen(tmp) + 1)];
        _capacity = 2 * (strlen(tmp) + 1);
    }
    strcpy(data, tmp);
    return;
}

void String::fitmem(char *s)
{
    if (_capacity <= (int)strlen(s) || _capacity > (int)(strlen(s) + 1) * 3)
    {
        if (s != data)
        {
            delete[] data;
            data = new char[2 * (strlen(s) + 1)];
            _capacity = 2 * (strlen(s) + 1);
            strcpy(data, s);
        }
        else
        {
            char tmp[strlen(s) + 1];
            strcpy(tmp, s);
            delete[] data;
            data = new char[2 * (strlen(tmp) + 1)];
            _capacity = 2 * (strlen(tmp) + 1);
            strcpy(data, tmp);
        }
    }
    else
        strcpy(data, s);
    return;
}

void String::init()
{
    data = NULL;
    _capacity = 0;
    _length = 0;
}