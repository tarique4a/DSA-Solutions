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
Node *rotateDLL(Node *head, int n)
{
    // Add your code here
    Node *tail = head;
    Node *curr = head;
    Node *p;
    while (tail->next)
    {
        tail = tail->next;
    }
    while (n--)
    {
        p = curr;
        curr = curr->next;
    }
    curr->prev = NULL;
    p->next = NULL;
    tail->next = head;
    head->prev = tail;
    return curr;
}