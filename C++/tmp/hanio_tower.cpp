#include <bits/stdc++.h>
using namespace std;

void Move(int n, char x, char y, char z);

int main(void)
{
    //��������
    int n;
    printf("�������������� ");
    scanf("%d", &n);
    printf("�ƶ��������£� \n");
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
        //�ݹ����
        Move(n - 1, x, z, y);
        //�ݹ����
        printf("%d# from %c to %c\n", n, x, z);
        Move(n - 1, y, x, z);
        //�ݹ����
    }
}