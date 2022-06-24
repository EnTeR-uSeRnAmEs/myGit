#include <bits/stdc++.h>
using namespace std;

#define NUM 20

//传入字符串数组时，不论是数组指针还是指针数组，传入的都应是数据的真实首地址位置

void InsertionSort_Origin(char *begin, char *end)
{
    int len = end - begin + 1;
    char key[NUM];
    for (int i = 1; i < len; i++)
    {
        memcpy(key, begin + i * NUM, NUM * sizeof(char));
        int j = i - 1;
        while ((j >= 0) && memcmp(key, begin + j * NUM, NUM * sizeof(char)) < 0)
        {
            memcpy(begin + (j + 1) * NUM, begin + j * NUM, NUM * sizeof(char));
            j--;
        }
        memcpy(begin + (j + 1) * NUM, key, NUM * sizeof(char));
    }
}

template <typename T>
void InsertionSort_Origin(T begin, T end)
{
    int len = end - begin + 1;
    for (int i = 1; i < len; i++)
    {
        int key = *(begin + i);
        int j = i - 1;
        while ((j >= 0) && (key < *(begin + j)))
        {
            *(begin + j + 1) = *(begin + j);
            j--;
        }
        *(begin + j + 1) = key;
    }
}

void InsertionSort_Binary(char *begin, char *end)
{
    int len = end - begin + 1;
    int i, j, m, low, high;
    char temp[NUM];
    for (i = 1; i < len; i++)
    {
        strcpy(temp, begin + i * NUM);
        low = 0;
        high = i - 1;
        while (low <= high)
        {
            m = (low + high) / 2;
            if (strcmp(begin + m * NUM, temp) > 0)
                high = m - 1;
            else
                low = m + 1;
        }
        for (j = i - 1; j >= high + 1; j--)
            strcpy(begin + (j + 1) * NUM, begin + j * NUM);
        strcpy(begin + (j + 1) * NUM, temp);
    }
}

template <class T>
void InsertionSort_Binary(T begin, T end)
{
    int len = end - begin + 1;
    int i, j, temp, m, low, high;
    for (i = 1; i < len; i++)
    {
        temp = *(begin + i);
        low = 0;
        high = i - 1;
        while (low <= high)
        {
            m = (low + high) / 2;
            if (*(begin + m) > temp)
                high = m - 1;
            else
                low = m + 1;
        }
        for (j = i - 1; j >= high + 1; j--)
            *(begin + j + 1) = *(begin + j);
        *(begin + j + 1) = temp;
    }
}

void InsertionSort_Shell(char *begin, char *end)
{
    int h = 1, len = end - begin + 1;
    while (h < len / 3)
        h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < len; i++)
        {
            for (int j = i; j >= h && strcmp(begin + j * NUM, begin + (j - h) * NUM) < 0; j -= h)
            {
                char tmp[NUM];
                strcpy(tmp, begin + j * NUM);
                strcpy(begin + j * NUM, begin + (j - h) * NUM);
                strcpy(begin + (j - h) * NUM, tmp);
            }
        }
        h = h / 3;
    }
}

template <typename T>
void InsertionSort_Shell(T begin, T end)
{
    int h = 1, len = end - begin + 1;
    while (h < len / 3)
        h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < len; i++)
        {
            for (int j = i; j >= h && *(begin + j) < *(begin + j - h); j -= h)
                swap(*(begin + j), *(begin + j - h));
        }
        h = h / 3;
    }
}

int main()
{
    // char a[][NUM] = {"hello", "world", "this", "is", "a", "test", "abandon", "bacteria", "zebra", "centry"};
    double a[] = {3, 32, 5, 25, 6, 245, 2, 345, 4, 43};
    // InsertionSort_Shell(a[0], a[0] + sizeof(a) / (sizeof(char) * NUM) - 1);
    InsertionSort_Shell(a, a + sizeof(a) / sizeof(double) - 1);
    for (auto i : a)
        cout << i << " ";
    system("pause");
    return 0;
}