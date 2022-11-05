
#ifndef __LM
#define __LM


#include<bits/stdc++.h>
#include "node.h"
using namespace std;


class list_son;
class list_father;


class node_son{
	private:
		int id;
		int dis;
		node_son *next = NULL;
		
	public:
		//void append(int id, int dis);
		//void del(int id);
		friend class list_son;
		friend void find_from_list_son(list_son &lst, node_son *&a, int id);
};

class list_son{
	private:
		node_son *head = NULL;
		int size;
		
	public:
		void append(int id, int dis);
		void print();
		void change(int id, int dis);
		void del(int id);
		friend void find_from_list_son(list_son &lst, node_son *&a, int id);
};

class node_father{
	private:
		int id;
		list_son son;
		node_father *next =  NULL;
		
	public:
		//void append(int id);
		//void del(int id);
		friend class list_father;
		friend void find_from_list_father(list_father &lst, node_father *&a, int id);
};

class list_father{
	private:
		node_father *head = NULL;
		int size;
				
	public:
		
		void build(int n, int m);//增加n个节点和m条边 
		
		void del_road(int a, int b);//删除a->b边 
		void del_node(int n);//删除节点n 
		void change(int a, int b, int d);//a->b边的长度改为d 
		
		void print();
		
		int find(int a, int b);//返回a->b的最短路 
		
		friend void find_from_list_father(list_father &lst, node_father *&a, int id);
};

void find_from_list_father(list_father &lst, node_father *&a, int id);
void find_from_list_son(list_son &lst, node_son *&a, int id);



#endif





