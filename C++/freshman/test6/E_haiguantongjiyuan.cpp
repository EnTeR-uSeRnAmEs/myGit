#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ship[1000][1000];
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            ship[i][j] = 0;
        }
    }
    int tmp;
    while (cin >> tmp)
    {
        int i = 0, j = 0;
        ship[i][j++] = tmp;
        if (cin.peek() == '\n')
        {
            i++;
            
            continue;
        }
    }

    system("pause");
    return 0;
}



/*
#include <iostream>

#include <cstdio>

#include <queue> //队列的STL的头文件

using namespace std;

int a[100005],sum,n,m,tmp;

struct node //存储时间与国籍的结构体

{

    int t;

    int g;

};

node b,f; //队列头与队列尾

queue <node> q; //声明类型为node结构体的队列

int main ()

{

    scanf("%d",&n);

    for (int i=1; i<=n; i++)

    {

        scanf("%d%d",&tmp,&m);

        for (int j=1; j<=m; j++)

        {

            node* nd=new node(); //声明新空间

            nd->t=tmp; //存入时间

            scanf("%d",&nd->g);

            a[nd->g]++; //存入同样国籍出现次数

            if (a[nd->g]==1) sum++; //如果此类国籍等于1,那么总国籍数目++

            q.push(*nd); //将临时结构体压入队列中

        }

        b=q.back(); //求队列尾

        f=q.front(); //求队列头

        while (b.t-f.t>=86400) //判断队列尾减去队列头是否有86400分钟

        {

            a[f.g]--; //减去同样国籍出现次数

            if (a[f.g]==0) sum--; //如果此类国籍等于0,那么总国籍数目--

            q.pop(); //弹出队列头

            f=q.front(); //更新队列头

        }

        printf("%d\n",sum);

    }

    return 0;

}
*/