#include <bits/stdc++.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <string.h>

using namespace std;

int main()
{
    int x = 42;
    auto f = [&x]{
        return x;
    };
    x = 0;
    auto y = f();
    cout << y << endl;
    system("pause");
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <string.h>
// int main()
// {
//     int a1,a2,a3;
//     char b1,b2,b3;
//     a1=0;
//     b1='+';
//     while (1)
//     {
//         scanf("%d %c",&a2,&b2);
 
//         while(b2=='*'||b2=='/')
//         {
//             scanf("%d %c",&a3,&b3);
//             if(b2=='*')a2=a2*a3;else a2=a2/a3;
//             b2=b3;
//         }
 
 
//         if(b1=='+')a1=a1+a2;
//         else if(b1=='-')a1=a1-a2;
 
//         b1=b2;
 
//         if(b1=='='){printf("%d\n",a1);break;}
//     }
//     system("pause");
//     return 0 ;
// }
