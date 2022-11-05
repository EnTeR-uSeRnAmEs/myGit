#pragma once
#include <iostream>
using namespace std;

template <typename T>
class base
{
protected:
	T *data;
	int _length;   // 个数
	int _capacity; // 容量

public:
	virtual ~base() = 0;
	virtual T &operator[](int i) = 0;
	virtual void fitmem(){};
	int getlength();
	int getcapacity();
	bool empty();
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
int base<T>::getlength()
{
	return _length;
};

template <typename T>
int base<T>::getcapacity()
{
	return _capacity;
};

template <typename T>
bool base<T>::empty()
{
	if (this->_length)
		return false;
	return true;
}