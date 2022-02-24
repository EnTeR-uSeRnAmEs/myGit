#include <bits/stdc++.h>
using namespace std;

void Move(int n, char x, char y, char z);

int main(void)
{
    //函数声明
    int n;
    printf("请输入盘子数： ");
    scanf("%d", &n);
    printf("移动步骤如下： \n");
    Move(n, 'A', 'B', 'C');
    system("pause");
    return 0;
}

void Move(int n, char x, char y, char z)
{
    if (n == 1) 
        printf("%d# from %c to %c\n", n, x, z);
    else
    {
        //递归出口
        Move(n - 1, x, z, y);
        //递归调用
        printf("%d# from %c to %c\n", n, x, z);
        Move(n - 1, y, x, z);
        //递归调用
    }
}