#include <bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node *next; 
};

struct Node *reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}