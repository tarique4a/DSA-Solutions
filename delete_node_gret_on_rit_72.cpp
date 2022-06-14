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
Node *rev(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *fst;
    while (curr)
    {
        fst = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fst;
    }
    return prev;
}
Node *compute(Node *head)
{
    head = rev(head);
    Node *curr = head;
    Node *prev = head;
    head = head->next;
    while (head)
    {
        if (head->data >= prev->data)
        {
            head = head->next;
            prev = prev->next;
        }
        else
        {
            prev->next = head->next;
            head = head->next;
        }
    }
    head = rev(curr);
    return head;
}