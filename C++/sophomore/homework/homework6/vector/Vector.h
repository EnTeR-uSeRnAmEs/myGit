#pragma once
#include <iostream>
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
			cout << "Size error! Different size of Vectors can't be added togerther!";
			return;
		}
		cout << "Unknown error!";
		return;
	}
};

template <typename T>
class Vector
{
private:
	T *data;
	int size;
	int capacity;

public:
	Vector<T>();
	Vector<T>(int n);
	Vector<T>(const Vector &v);
	~Vector();
	// 0.????·?????
	Vector<T> operator+(const Vector<T> &v) throw(ERROR);
	Vector<T> &operator+=(const Vector<T> &v) throw(ERROR);
	Vector<T> &operator=(const Vector<T> &v);
	bool operator==(const Vector<T> &v);
	bool operator!=(const Vector<T> &v);
	T &operator[](int i) throw(ERROR);
	void push_back(T ele);
	int getsize();
	int getcapacity();
	bool empty();
	T front() throw(ERROR);
	T back() throw(ERROR);
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
	data = NULL;
	size = 0;
	capacity = 0;
}

template <typename T>
Vector<T>::Vector(int n)
{
	data = new T[n]; //开辟大小为n的空间，并返回头指针
	size = 0;
	capacity = n;
}

template <typename T>
Vector<T>::Vector(const Vector &v)
{
	int n = v.capacity;
	data = new T[n]; //开辟大小为n的空间，并返回头指针
	for (int i = 0; i < n; i++)
	{
		data[i] = v.data[i];
	}
	size = v.size;
	capacity = v.capacity;
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] data;
	data = NULL;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &v) throw(ERROR)
{
	if (size != v.size) //向量维数不同，无法相加
	{
		throw ERROR(2); //抛出异常类对象
	}
	int n = size;
	Vector<T> v2(n);
	for (int i = 0; i < n; i++)
	{
		v2.data[i] = data[i] + v.data[i];
	}
	v2.capacity = capacity;
	v2.capacity = capacity;
	v2.size = size;
	return v2;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &v) throw(ERROR)
{
	if (size != v.size) //向量维数不同，无法相加
	{
		throw ERROR(2); //抛出异常类对象
	}
	else
	{
		int n = size;
		for (int i = 0; i < n; i++)
		{
			data[i] += v.data[i];
		}
	}
	return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &v)
{
	if (*this == v)
		return *this; //若自己赋值给自己，则直接返回
	int n = v.size;
	if (data != NULL) //先释放原先的空间
	{
		delete[] data;
		data = NULL;
	}
	data = new T[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = v.data[i];
	}
	capacity = v.capacity;
	size = v.size;
	return *this;
}

template <typename T>
ostream &operator<<(ostream &cout, Vector<T> &v)
{
	int n = v.size;
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
	if (size != v.size) //向量维数不同，一定不等
	{
		return false;
	}
	else
	{
		int is_same = 1;
		for (int i = 0; i < size; i++)
		{
			if (data[i] != v.data[i])
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
	if (i > (size - 1) || i < 0)
	{
		throw ERROR(1); //抛出越界异常
	}
	return data[i];
}

template <typename T>
void Vector<T>::push_back(T ele)
{
	if (size < capacity)
	{
		data[size] = ele;
		size++;
	}
	else //如果空间不够，则new一片大小足够的新空间，并将原来的数据复制到新空间，接着delete旧空间
	{
		int n = size + 1;
		Vector<T> v(*this);
		if (data != NULL)
		{
			delete[] data;
			data = NULL;
		}
		data = new T[n];
		for (int i = 0; i < size; i++)
		{
			data[i] = v.data[i];
		}
		capacity = n;
		data[size] = ele;
		size++;
	}
}

template <typename T>
int Vector<T>::getsize()
{
	return size;
}

template <typename T>
int Vector<T>::getcapacity()
{
	return capacity;
}

template <typename T>
bool Vector<T>::empty()
{
	if (size)
		return false;
	return true;
}

template <typename T>
T Vector<T>::front() throw(ERROR)
{
	if (this->size == 0)
		throw ERROR(1);
	else
		return this->data[0];
}

template <typename T>
T Vector<T>::back() throw(ERROR)
{
	if (this->size == 0)
		throw ERROR(1);
	else
		return this->data[this->size - 1];
}

template <typename T>
T *Vector<T>::begin() throw(ERROR)
{
	if (this->size == 0)
		throw ERROR(1);
	else
		return this->data;
}

template <typename T>
T *Vector<T>::end() throw(ERROR)
{
	if (this->size == 0)
		throw ERROR(1);
	else
		return this->data + this->size;
}

template <typename T>
void Vector<T>::pop_back() throw(ERROR)
{
	if (this->size == 0)
		throw ERROR(1);
	size--;
}

template <typename T>
void Vector<T>::erase(T *p) throw(ERROR)
{
	if (p >= this->end() || p < this->begin())
		throw ERROR(1);
	size--;
	for (T *i = p; i < this->end(); i++)
		*i = *(i + 1);
	return;
}

template <typename T>
void Vector<T>::clear()
{
	size = 0;
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
