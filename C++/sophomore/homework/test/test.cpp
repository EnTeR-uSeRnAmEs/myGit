#include <bits/stdc++.h>

template <typename T>
class base
{
protected:
    T *data;
    int _length;
    int _capacity;

public:
    virtual ~base() = 0;
};

template <typename T>
base<T>::~base()
{
    // cout << "基类的纯虚析构已调用！";
    if (data != NULL)
    {
        delete[] data;
        data = NULL;
    }
}

template <typename T>
class vector<T> : public base
{
public:
    vector<T>();
    vector<T>(const vector<T>);
}

template <typename T>
Vector<T>::Vector()
{
    this->data = NULL;
    this->_length = 0;
    this->_capacity = 0;
}
template <typename T>
Vector<T>::Vector(int n)
{
    this->data = new T[n]; // 开辟大小为n的空间，并返回头指针
    this->_length = 0;
    this->_capacity = n;
}

template <typename T>
Vector<T>::Vector(const Vector &v)
{
    int n = v._capacity;
    this->data = new T[n]; // 开辟大小为n的空间，并返回头指针
    for (int i = 0; i < n; i++)
    {
        this->data[i] = v.data[i];
    }
    this->_length = v._length;
    this->_capacity = v._capacity;
}
