#include <iostream>
using namespace std;

int main()
{
    char name[20];
    int age;
    cout << "What's your name?" << endl; // cin/cout：可定向输出
    cin.getline(name, 20);
    cout << "How old are you?" << endl;
    cin >> age;
    clog << "Name:" << name << endl //有缓存不可定向输出（cerr无缓存不可定向输出）
         << "Age:" << age << endl;
    system("pause");
    return 0;
}