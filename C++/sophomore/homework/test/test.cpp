#include <bits/stdc++.h>

class String
{
private:
    char *data = NULL;
    int _capacity;
    int _length;

public:
    int getlength();
    int getcapacity();
};

int String::getlength() const
{
    return strlen(data);
}

template <typename T>
int base<T>::getcapacity()
{
    return _capacity;
};
String String::substr(int pos, int n) const
{
    String temp(*this, pos, n);
    return temp;
}
