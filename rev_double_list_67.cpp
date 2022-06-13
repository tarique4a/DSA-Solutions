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
Node *reverseDLL(Node *head)
{
    // Your code here
    Node *curr = head;
    Node *pich = NULL;
    Node *aage = NULL;
    while (curr)
    {
        aage = curr->next;
        curr->next = pich;
        curr->prev = aage;
        pich = curr;
        curr = aage;
    }

    return pich;
}