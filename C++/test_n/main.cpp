#include <iostream>
using namespace std;

int main()
{
    int a, b, num[a][b] = {0};
    cin >> a >> b;
    for (int i = 0; i < a; i++) 
    {
        for (int j = 0; j < b; j++) 
        {
            int k;
            cin >> k;
            num[i][j] = k;
        }
    }
    system("pause");
    return 0;
}