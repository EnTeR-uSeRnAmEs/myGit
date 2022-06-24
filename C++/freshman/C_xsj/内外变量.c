#include <stdio.h>
 
// 函数外定义变量 x 和 y
int x=1;
int y=1;
int add1()
{
    // 函数内声明变量 x 和 y 为外部变量
    int x;
    int y;
    // 给外部变量（全局变量）x 和 y 赋值
    x = 1;
    y = 2;
    return x+y;
}

int add2()
{
    // 函数内声明变量 x 和 y 为外部变量
    extern int x;
    extern int y;
    // 给外部变量（全局变量）x 和 y 赋值
    x = 1;
    y = 2;
    return x+y;
}

int main()
{
    int result;
    // 调用函数 addtwonum    
    printf("result:\t%d\n",add1());
    printf("x+y:\t%d\n",x+y);
    printf("result:\t%d\n",add2());
    printf("x+y:\t%d\n",x+y);

    return 0;
}