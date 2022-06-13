#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    int c1 = 0, c2 = 0;
    while (temp1 != NULL)
    {
        c1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        c2++;
        temp2 = temp2->next;
    }
    bool flg = false;
    int c;
    Node *curr;
    if (c1 >= c2)
    {
        c = c1 - c2;
        curr = head1;
        flg = true;
    }
    else
    {
        c = c2 - c1;
        curr = head2;
    }
    while (c--)
    {
        curr = curr->next;
    }
    if (flg)
    {
        temp2 = head2;
        while (curr != NULL || temp2 != NULL)
        {
            if (curr == temp2)
                return curr->data;
            else
            {
                curr = curr->next;
                temp2 = temp2->next;
            }
        }
    }
    else
    {
        temp1 = head1;
        while (curr != NULL || temp1 != NULL)
        {
            if (curr == temp1)
                return curr->data;
            else
            {
                curr = curr->next;
                temp1 = temp1->next;
            }
        }
    }

    return -1;
}