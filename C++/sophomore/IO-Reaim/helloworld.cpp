#include <iostream>
using namespace std;

int main()
{
    char name[20];
    int age;
    cout << "What's your name?" << endl; // cin/cout���ɶ������
    cin.getline(name, 20);
    cout << "How old are you?" << endl;
    cin >> age;
    clog << "Name:" << name << endl //�л��治�ɶ��������cerr�޻��治�ɶ��������
         << "Age:" << age << endl;
    system("pause");
    return 0;
}