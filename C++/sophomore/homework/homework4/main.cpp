#include <bits/stdc++.h>
#include "node.h"
#include "list_map.h"
using namespace std;

int main()
{
	list_father lst;
	lst.build(3, 2);
	lst.build(4, 0);
	lst.print();
	int a, b;
	cin >> a >> b;
	lst.del_road(a, b);
	lst.print();
	system("pause");
	return 0;
}

// 1.�˵�(main.cpp)��дfind_from_list_son //��
// 2.ɾ��(ע��ɾlist_son) //��
// 3.�ġ�ɾ�� //��

/*
4 5








*/
