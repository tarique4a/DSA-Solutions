#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *removeDuplicates(Node *head)
{
    Node *cur = head;
    Node *temp = head->next;
    while (temp != NULL)
    {
        if (cur->data == temp->data)
        {
            cur->next = temp->next;
            delete temp;
            temp = cur->next;
        }
        else
        {
            cur = cur->next;
            temp = temp->next;
        }
    }
    return head;
}