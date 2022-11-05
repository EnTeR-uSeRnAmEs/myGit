#include "list_map.h"
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
