#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

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
    for (; p->next; p = p->next)
        ;
    p->next = tmp;
    return tmp;
}

void FreeList(Node *&pHead)
{
    Node *tmp = pHead->next;
    for (; pHead; delete pHead)
    {
        pHead = tmp;
        if (tmp)
            tmp = tmp->next;
    }
    pHead = NULL;
    return;
}

int main()
{
    Node *pHead;
    int data[] = {1, 2, 4, 6, 7, 3, 2, 5};
    pHead = Create(pHead, sizeof(data) / sizeof(data[0]), data);
    cout << NumNodes(pHead) << endl;
    ShowList(pHead);
    cout << endl;
    Insert(pHead, 10);
    Append(pHead, 9);
    ShowList(pHead);
    cout << endl;
    FreeList(pHead);
    cout << pHead << endl;
    system("pause");
    return 0;
}