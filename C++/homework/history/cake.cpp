#include <iostream>
using namespace std;

int main()
{
    int num, n, ATP;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        ATP = 0;
        cin >> n;
        for (int x = 1; x < n; x++){ATP += x;}
        if (ATP == 0) {cout << "Mission Complete!" << endl;}
        else if (ATP == 1) {cout << "Needs at least 1 ATP!" << endl;}
        else {cout << "Needs at least " << ATP << " ATPs!" << endl;}
    }
    // system("pause");
    return 0;
}