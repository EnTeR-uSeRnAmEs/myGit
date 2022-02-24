#include <iostream>
using namespace std;

int main()
{
    int times, grade1, grade2, grade3;
    cin >> times;
    for (int i = 0; i < times; i++) 
    {
        cin >> grade1 >> grade2 >> grade3;
        cout << int (grade1 * 0.45 + grade2 *0.45 + grade3 * 0.1) << endl;
    }
    system("pause");
    return 0;
}