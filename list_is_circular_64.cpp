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
bool isCircular(Node *head)
{
    // Your code here
    Node *curr = head;
    curr = curr->next;
    if (curr == NULL)
        return false;
    while (curr)
    {
        if (curr == head)
            return true;
        curr = curr->next;
    }
    return false;
}