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

#include <queue> //���е�STL��ͷ�ļ�

using namespace std;

int a[100005],sum,n,m,tmp;

struct node //�洢ʱ��������Ľṹ��

{

    int t;

    int g;

};

node b,f; //����ͷ�����β

queue <node> q; //��������Ϊnode�ṹ��Ķ���

int main ()

{

    scanf("%d",&n);

    for (int i=1; i<=n; i++)

    {

        scanf("%d%d",&tmp,&m);

        for (int j=1; j<=m; j++)

        {

            node* nd=new node(); //�����¿ռ�

            nd->t=tmp; //����ʱ��

            scanf("%d",&nd->g);

            a[nd->g]++; //����ͬ���������ִ���

            if (a[nd->g]==1) sum++; //��������������1,��ô�ܹ�����Ŀ++

            q.push(*nd); //����ʱ�ṹ��ѹ�������

        }

        b=q.back(); //�����β

        f=q.front(); //�����ͷ

        while (b.t-f.t>=86400) //�ж϶���β��ȥ����ͷ�Ƿ���86400����

        {

            a[f.g]--; //��ȥͬ���������ִ���

            if (a[f.g]==0) sum--; //��������������0,��ô�ܹ�����Ŀ--

            q.pop(); //��������ͷ

            f=q.front(); //���¶���ͷ

        }

        printf("%d\n",sum);

    }

    return 0;

}
*/