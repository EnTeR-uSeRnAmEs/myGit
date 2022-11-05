#include <bits/stdc++.h>
#include "list_map.h"
using namespace std;

void find_from_list_son(list_son &lst, node_son *&a, int id)
{
	a = lst.head;
	while (a->next != NULL)
	{
		if (a->id == id)
			break;
		a = a->next;
	}
	if (a->id != id)
		a = NULL;
}

void find_from_list_father(list_father &lst, node_father *&a, int id)
{
	a = lst.head;
	while (a->next != NULL)
	{
		if (a->id == id)
			break;
		a = a->next;
	}
	if (a->id != id)
		a = NULL;
}

void list_son::change(int id, int dis)
{
	node_son *p_son;
	find_from_list_son(*this, p_son, id);
	if (p_son != NULL)
		p_son->dis = dis;
	else
		return;
}

void list_son::del(int id)
{
	node_son *p_son, *pp_son = NULL;
	p_son = head;
	if (p_son == NULL)
		return;
	while (p_son->next != NULL)
	{
		if (p_son->id == id)
		{
			if (p_son == head)
				head = p_son->next;
			else
				pp_son->next = p_son->next;
			delete p_son;
		}
		pp_son = p_son;
		p_son = p_son->next;
	}
	if (p_son->id != id)
	{
		p_son = NULL;
		pp_son = NULL;
	}
	if (p_son != NULL)
	{
		if (p_son == head)
			head = p_son->next;
		else
			pp_son->next = p_son->next;
		delete p_son;
	}
	else
		return;
}

void list_son::append(int id, int dis)
{
	if (this->head == NULL)
	{
		this->head = new node_son;
		this->head->id = id;
		this->head->dis = dis;
		return;
	}
	node_son *now = this->head;
	while (now->next != NULL)
		now = now->next;
	node_son *next = new node_son;
	next->id = id;
	next->dis = dis;
	next->next = NULL;
	now->next = next;
	return;
}

void list_father::build(int n, int m)
{
	this->size += n;
	if (this->head == NULL)
	{
		n--;
		this->head = new node_father;
		this->head->id = 1;
		this->head->next = NULL;
	}

	node_father *head = this->head;
	node_father *now = head;
	while (now->next != NULL)
		now = now->next;

	node_father *next;
	int id = now->id;
	for (int i = 1; i <= n; i++)
	{
		next = new node_father;
		next->id = id + i;
		next->next = NULL;
		now->next = next;
		now = next;
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b, d;
		cout << "请输入第" << i << "条路径\n";
		cin >> a >> b >> d;
		node_father *p = NULL;
		node_father *p2 = NULL;
		find_from_list_father(*this, p, a); //有问题, 没找到就寄
		find_from_list_father(*this, p2, b);

		if (p != NULL && p2 != NULL)
			p->son.append(b, d);
		else
		{
			cout << "输入错误!\n";
			i--;
		}
	}
}

void list_father::del_node(int n)
{
}

void list_father::del_road(int a, int b)
{
	node_father *p_father;
	find_from_list_father(*this, p_father, a);
	if (p_father != NULL)
		p_father->son.del(b);
	else
		return;
}

void list_father::change(int a, int b, int d)
{
	node_father *p_father;
	find_from_list_father(*this, p_father, a);
	if (p_father != NULL)
		p_father->son.change(b, d);
	else
		return;
}

void list_son::print()
{
	if (this->head == NULL)
		return;
	node_son *now = this->head;
	while (now->next != NULL)
	{
		cout << now->id << " " << now->dis << endl;
		now = now->next;
	}
	cout << now->id << " " << now->dis << endl;
	return;
}

void list_father::print()
{
	node_father *now = this->head;
	while (now->next != NULL)
	{
		cout << now->id << endl;
		now->son.print();
		cout << "|\nV \n";
		now = now->next;
	}
	cout << now->id << endl;
	now->son.print();
	return;
}
