#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int lights, people;
    while (cin >> lights >> people)
    {
        int light[101] = {0}, On_lights = 0;
        for (int i = 1; i <= people; i++)
        {
            for (int j = 1; j <= lights; j++)
            {
                if (j % i == 0) 
                {
                    if (light[j - 1]) light[j - 1] = 0;
                    else light[j - 1] = 1;
                }
            }
            for (int j = 0; j < lights; j++) cout << light[j];
            cout << endl;
        }
        for (int i = 0; i < lights; i++)
        {
            if (!light[i]) On_lights++;
        }
        cout << On_lights << endl;
    }
    system("pause");
    return 0;
}