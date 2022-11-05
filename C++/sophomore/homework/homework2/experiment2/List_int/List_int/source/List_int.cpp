// List_int.cpp	������ͷ��㣩������������
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "List_int.h"
using namespace std;

// ����Ϊ4�������ĺ����Ķ��壬�亯������������ԭ�ͣ���List_int.h�ļ�

/* ��ʾ��������������� <<��ʹ֮�ܹ�������Node *�����ͽ������
1. ����� << ��˫Ŀ���㣬����Ҫ���������������� cout << a; �У�cout�ǵ�һ��������a�ĵڶ�����������
2. operator<< Ϊ��������������ʽ��������Ϊ��һ���ڶ���������
3. ��һ����ʽ����Ϊ�����Ͳ�����������std���ֿռ��е�ȫ�ֶ���cout����ͬһ���������͡�
   �༴���������£�����out����cout������������out��cout�ı�������
   Ȼ������������cout��ʵ�Ρ������������ļ�������ʵ�Σ���ô�Ϳ���ֱ��������ļ���
4. �ڶ�����ʽ�������ڴ���������׵�ַ��
5. �����ķ���������Ƴɣ����÷���out��������ֵ���أ������ⴴ�����(�豸)���󣬶���ֱ�ӷ��ص�һ�������󶨵����(�豸)����
   �༴�������һ�������� cout����ô������Ҳ���� cout���������ɱ�֤����� << ʵ���������
   ����������ʽ��cout << a << ", " << b ʵ������ (((cout << a) << ", ") << b������(cout << a)����cout��
   �ʿ��Լ���ִ��(cout << ", ")���������cout����һ��ִ�� cout << b���������cout��
*/
ostream &operator<<(ostream &out, const Node *head) // ��������������<<����ʹ���ܹ�ֱ���������<<�����������
{													// ����C++����printf�������������ԭ��֮һ
	for (; head != NULL; head = head->next)
		out << head->data << endl; // �����ÿ����������ռһ��
	return out;
}

/* ˼����
1. ��ʽ����newsearch��������ʲô�� ��ʼ�µĲ���ʱ��ʼ��p��data��k
2. ��ʽ���� num �к����ã� ���ؽڵ���
3. ΪʲôҪ�� p��k��data ��Ƴɾ�̬�ֲ������� ����ʹ��Locate()����ͬһ��Ԫ��ʱ�����ᷴ������p��data��k��ʹk�ܹ�����
4. �ֲ��Զ�ָ����� temp ��������ʲô�� �����ҵ����ݵĽڵ�
5. �����ķ���ֵ��ʲô����������Ƿ��ҵ����������Ľ��  Node *��������ֵ��ΪNULLʱΪ�ҵ��ڵ�
6. ���β�newsearchΪfalse����ʱ�β� x �������ã�ΪʲôҪ������ƣ� ������
�𣺶���һ�����������������ܴ�������һ�������ļ�����������ˣ���ʱ��Ҫ����ϵ�x��
*/
Node *Locate(Node *head, int x, int &num, bool newsearch)
{
	static Node *p = head;
	static int data = x; // ���������������ͬ
	static int k = 0;	 // ���ͣ�������
	Node *temp;
	if (newsearch)
	{
		p = head;
		data = x;
		k = 0;
	}
	for (; p != NULL && p->data != data; p = p->next, k++) // �������"��ǰ"������������
		;
	temp = p;
	num = k;
	if (p != NULL) // ����ҵ����ڷ����ҵ��Ľ���ַ��temp��֮ǰ��p"����"����ǰ��һ����Ϊ������������׼��
	{
		p = p->next;
		k++;
	}
	return temp;
}

/* ��ʾ
1. �õ��ļ����༰����󣨲μ��̲ĵ�14�µ�2�� �ļ�I/O������
2. �˴����ļ�����Ĭ�ϵ��ı��ļ���ʽ��
3. ������������������������(int)��Ҫ���ܽ��� << �� >> ����(OK)��
4. ������ļ��ĸ�ʽҪ�ܹ�ʹLoad������ȷ�ض�ȡ��
*/
int Save(const char *filename, const Node *head)
{
	ofstream outfile(filename); // ���ļ������ڽ�����д�����У�
	if (outfile.fail())
		return 0;
	int n = 0;									// ���ڼ��������ͱ���
#if (1)											// �� #if(1) �ĳ� #if(0) �Կ�
	const Node *p;								// �������Ϊ��n�ļ������˴�����ֱ���� outfile << head; ȡ������� for ѭ��
	for (p = head; p != NULL; p = p->next, n++) // ��������������������������������ļ���
		outfile << p->data << endl;
#else
	outfile << head; // ���� operator<< ����
	n = NumNodes(head);
#endif
	outfile.close(); // �ر��ļ������������е���������д�뵽�ļ��У���һ�����Ҫ��
	return n;
}

int Load(const char *filename, Node *&head)
{
	int n;					   // ���ڼ��������ͱ���
	int x;					   // ��������������ͬ�ı���
	ifstream infile(filename); // ���ļ������ڶ�ȡ���е����ݣ�
	if (infile.fail())
		return 0;
	for (n = 0; infile >> x; n++) // �������ļ��ж�ȡ���ݣ����γ�һ������
		Append(head, x);
	infile.close(); // �ر��ļ�
	return n;
}

// ���ڴ����6��������Create��NumNodes��ShowList��Insert��Append��FreeList���Ķ���
Node *Create(Node *&pHead, int len, int arr[])
{
	if (!pHead)
		pHead = new Node;
	if (pHead->next)
		pHead->next = NULL;
	Node *p = &(*pHead);
	for (int i = 0; i < len; ++i)
	{
		Node *tmp = new Node;
		tmp->data = arr[i];
		tmp->next = NULL;
		p->next = tmp;
		p = tmp;
	}
	p = pHead;
	pHead = pHead->next;
	delete p;
	return pHead;
}

int NumNodes(const Node *pHead)
{
	const Node *tmp = pHead;
	int i = 0;
	for (; tmp; ++i)
		tmp = tmp->next;
	return i;
}

void ShowList(const Node *pHead)
{
	const Node *tmp = pHead;
	cout << "head";
	for (; tmp; tmp = tmp->next)
		cout << " -> " << tmp->data;
	cout << " -> NULL";
	return;
}

Node *Insert(Node *&pHead, int data)
{
	Node *tmp = new Node;
	if (pHead)
		tmp->next = pHead;
	else
		tmp->next = NULL;
	tmp->data = data;
	pHead = tmp;
	return pHead;
}

Node *Append(Node *&pHead, int data)
{
	Node *tmp = new Node;
	Node *p = pHead;
	tmp->data = data;
	tmp->next = NULL;
	if (!p)
	{
		pHead = tmp;
		return tmp;
	}
	for (; p->next;)
		p = p->next;
	p->next = tmp;
	return tmp;
}

void FreeList(Node *&pHead)
{
	Node *tmp;
	if (pHead)
		tmp = pHead->next;
	for (; pHead;)
	{
		delete pHead;
		pHead = tmp;
		if (tmp)
			tmp = tmp->next;
	}
	return;
}