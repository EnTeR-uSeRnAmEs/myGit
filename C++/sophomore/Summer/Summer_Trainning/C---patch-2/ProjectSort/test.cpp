#include <bits/stdc++.h>
#include "MySort.h"
using namespace std;

int main()
{
    // char a[][NUM] = {"hello", "world", "this", "is", "a", "test", "abandon", "bacteria", "zebra", "centry"};
    double a[] = {3, 32, 5, 25, 6, 245, 2, 345, 4, 43};
    // InsertionSort_Shell(a[0], a[0] + sizeof(a) / (sizeof(char) * NUM) - 1);
    InsertionSort(a, a + sizeof(a) / sizeof(double) - 1);
    for (auto i : a)
        cout << i << " ";
    system("pause");
    return 0;
}