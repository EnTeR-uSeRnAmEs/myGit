#include <iostream>
#include <algorithm>
using namespace std;

string sort(string str)
{
    for(int i = 1; i < int(str.length()); i++)
    {
        char key = str[i];
        int j = i - 1;
        while((j >= 0) && (key < str[j]))
        {
            str[j+1] = str[j];
            j--;
        }
        str[j+1] = key;
    }
    return str;
}

string permutation(string str)
{
    for (int i = 0; i < int(str.length()); i++)
    {
        if (i != str.length() - 1)
        {
            cout << str[i];
            return permutation(str.substr(i+1));
        }
        else
        {
            cout << str[i] << endl;
        }
        cout 
    }
}

int main() 
{
    string str;
    while (cin >> str) 
    {
        cout  << sort(str) << endl;
    }
    system("pause");
}