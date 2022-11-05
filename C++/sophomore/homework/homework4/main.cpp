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

// 1.菜单(main.cpp)、写find_from_list_son //周
// 2.删点(注意删list_son) //苏
// 3.改、删边 //陈

/*
4 5








*/
