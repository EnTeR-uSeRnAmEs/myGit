#include <bits/stdc++.h>
using namespace std;

struct node
{
    string address = "";
    int danger = 0;
    node *next = NULL;
};

void Listsort(node *pHead, int len)
{
    node *ptmp = pHead;
    while (--len)
    {
        while (ptmp->next != NULL)
        {
            if (ptmp->danger < ptmp->next->danger)
            {
                swap(ptmp->next->danger, ptmp->danger);
                swap(ptmp->next->address, ptmp->address);
            }
            ptmp = ptmp->next;
        }
        ptmp = pHead;
    }
    return;
}

void DisplayList(node *pHead)
{
    node *ptmp = pHead;
    do
    {
        cout << ptmp->address << " " << ptmp->danger << endl;
        ptmp = ptmp->next;
    } while (ptmp != NULL);
    return;
}

int main()
{
    int danger, len = 0;
    string address;
    node *pHead = NULL, *ptmp = NULL;
    while (cin >> address >> danger)
    {
        ++len;
        if (pHead == NULL)
        {
            pHead = new node;
            ptmp = pHead;
        }
        else
        {
            ptmp->next = new node;
            ptmp = ptmp->next;
        }
        ptmp->next = NULL;
        ptmp->address = address;
        ptmp->danger = danger;
    }
    Listsort(pHead, len);
    DisplayList(pHead);
    return 0;
}