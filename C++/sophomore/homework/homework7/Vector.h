#pragma once
#include <iostream>
#include "base.h"
using namespace std;

class ERROR
{
private:
	int type; // 1:out of range
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
		else if (type == 2)
		{
			cout << "length error! Different length of Vectors can't be added togerther!";
			return;
		}
		else
		{
			cout << "Unknown error!";
			return;
		}
	}
};

template <typename T>
class Vector : public base<T>
{
public:
	Vector<T>();
	Vector<T>(int n);
	Vector<T>(const Vector &v);
	~Vector();
	// 0.运算符重载
	Vector<T> operator+(const Vector<T> &v) throw(ERROR);
	Vector<T> &operator+=(const Vector<T> &v) throw(ERROR);
	Vector<T> &operator=(const Vector<T> &v);
	bool operator==(const Vector<T> &v);
	bool operator!=(const Vector<T> &v);
	T &operator[](int i) throw(ERROR);
	void fitmem();
	void push_back(T ele);
	int getlength();
	int getcapacity();
	bool empty();
	T &front() throw(ERROR);
	T &back() throw(ERROR);
	T *begin() throw(ERROR);
	T *end() throw(ERROR);
	void pop_back() throw(ERROR);
	void erase(T *pos) throw(ERROR);
	void clear();
	void insert(T *pos, T ele) throw(ERROR);
	T *find(T *pos, T ele) throw(ERROR);
	friend ostream &operator<< <T>(ostream &cout, Vector<T> &v);
	friend istream &operator>><T>(istream &cin, Vector<T> &v);
};

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

template <typename T>
Vector<T>::~Vector()
{
	cout << "子类Vector析构已调用!  ";
	if (this->data != NULL)
		delete[] this->data;
	this->data = NULL;
}

template <typename T>
void Vector<T>::fitmem()
{
	int n;
	if (this->_length == 0)
		n = 1;
	else
		n = this->_length * 2;
	T *temp = new T[n];
	for (int i = 0; i < this->_length; i++)
	{
		temp[i] = this->data[i];
	}
	this->_capacity = n;
	if (this->data != NULL)
	{ // 释放data空间
		delete[] this->data;
	}
	this->data = temp;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &v) throw(ERROR)
{
	if (this->_length != v._length)
	{					// 向量维数不同，无法相加
		throw ERROR(2); // 抛出异常类对象
	}
	int n = this->_length;
	Vector<T> v2(n);
	for (int i = 0; i < n; i++)
	{
		v2.data[i] = this->data[i] + v.data[i];
	}
	v2._capacity = this->_capacity;
	v2._capacity = this->_capacity;
	v2._length = this->_length;
	return v2;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &v) throw(ERROR)
{
	if (this->_length != v._length)
	{					// 向量维数不同，无法相加
		throw ERROR(2); // 抛出异常类对象
	}
	else
	{
		int n = this->_length;
		for (int i = 0; i < n; i++)
		{
			this->data[i] += v.data[i];
		}
	}
	return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &v)
{
	if (*this == v)
		return *this; // 若自己赋值给自己，则直接返回
	int n = v._length;
	if (this->data != NULL)
	{ // 先释放原先的空间
		delete[] this->data;
		this->data = NULL;
	}
	this->data = new T[n];
	for (int i = 0; i < n; i++)
	{
		this->data[i] = v.data[i];
	}
	this->_capacity = v._capacity;
	this->_length = v._length;
	return *this;
}

template <typename T>
ostream &operator<<(ostream &cout, Vector<T> &v)
{
	int n = v._length;
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			cout << v.data[i] << " ";
		}
		else
		{
			cout << v.data[i];
		}
	}
	return cout;
}

template <typename T>
istream &operator>>(istream &cin, Vector<T> &v)
{
	T ele;
	while (cin >> ele)
	{
		v.push_back(ele);
		if (cin.peek() == '\n')
			break;
	}
	return cin;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &v)
{
	if (this->_length != v._length)
	{ // 向量维数不同，一定不等
		return false;
	}
	else
	{
		int is_same = 1;
		for (int i = 0; i < this->_length; i++)
		{
			if (this->data[i] != v.data[i])
			{
				is_same = 0;
				break;
			}
		}
		if (is_same == 1)
		{
			return true;
		}
		else
			return false;
	}
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T> &v)
{
	if (*this == v)
	{
		return false;
	}
	else
		return true;
}

template <typename T>
T &Vector<T>::operator[](int i) throw(ERROR)
{
	if (i > (this->_length - 1) || i < 0)
	{
		throw ERROR(1); // 抛出越界异常
	}
	return this->data[i];
}

template <typename T>
void Vector<T>::push_back(T ele)
{
	if (this->_length < this->_capacity)
	{
		this->data[this->_length] = ele;
		this->_length++;
	}
	else
	{
		this->fitmem();
		this->data[this->_length] = ele;
		this->_length++;
	}
}

template <typename T>
int Vector<T>::getlength()
{
	return this->_length;
}

template <typename T>
int Vector<T>::getcapacity()
{
	return this->_capacity;
}

template <typename T>
bool Vector<T>::empty()
{
	if (this->_length)
		return false;
	return true;
}

template <typename T>
T &Vector<T>::front() throw(ERROR)
{
	if (this->_length == 0)
		throw ERROR(1);
	else
		return this->data[0];
}

template <typename T>
T &Vector<T>::back() throw(ERROR)
{
	if (this->_length == 0)
		throw ERROR(1);
	else
		return this->data[this->_length - 1];
}

template <typename T>
T *Vector<T>::begin() throw(ERROR)
{
	if (this->_length == 0)
		throw ERROR(1);
	else
		return this->data;
}

template <typename T>
T *Vector<T>::end() throw(ERROR)
{
	if (this->_length == 0)
		throw ERROR(1);
	else
		return this->data + this->_length;
}

template <typename T>
void Vector<T>::pop_back() throw(ERROR)
{
	if (this->_length == 0)
		throw ERROR(1);
	this->_length--;
}

template <typename T>
void Vector<T>::erase(T *p) throw(ERROR)
{
	if (p >= this->end() || p < this->begin())
		throw ERROR(1);
	this->_length--;
	for (T *i = p; i < this->end(); i++)
		*i = *(i + 1);
	return;
}

template <typename T>
void Vector<T>::clear()
{
	this->_length = 0;
	return;
}

template <typename T>
void Vector<T>::insert(T *pos, T ele) throw(ERROR)
{
	if (pos > this->end() || pos < this->begin())
		throw ERROR(1);
	this->push_back(ele);
	for (T *i = this->end() - 1; i > pos; i--)
	{
		*i = *(i - 1);
	}
	*pos = ele;
	return;
}

template <typename T>
T *Vector<T>::find(T *p, T ele) throw(ERROR)
{
	if (p >= this->end() || p < this->begin())
		throw ERROR(1);
	while (p != this->end())
	{
		if (*p == ele)
			break;
		p++;
	}
	return p;
}
