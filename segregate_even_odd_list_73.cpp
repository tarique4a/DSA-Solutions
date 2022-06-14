#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *divide(int N, Node *head)
{
    // code here
    Node *eve = NULL;
    Node *odd = NULL;
    Node *e = NULL;
    Node *o = NULL;
    while (head)
    {
        if ((head->data % 2) == 0)
        {
            if (eve == NULL)
            {
                eve = head;
                e = head;
            }
            else
            {
                e->next = head;
                e = e->next;
            }
        }
        else
        {
            if (odd == NULL)
            {
                odd = head;
                o = head;
            }
            else
            {
                o->next = head;
                o = o->next;
            }
        }
        head = head->next;
    }
    if (e)
        e->next = odd;
    if (o)
        o->next = NULL;
    if (eve)
        return eve;
    else
        return odd;
}