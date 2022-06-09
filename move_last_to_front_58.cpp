#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *moveToFront(Node *head)
{
    Node *temp = head;
    Node *temp2;
    if (temp->next == NULL)
        return head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = NULL;
    temp2->next = head;
    head = temp2;
    return head;
}