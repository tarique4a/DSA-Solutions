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
Node *segregate(Node *head)
{
    int m[3] = {0};
    for (Node *temp = head; temp != NULL; temp = temp->next)
    {
        m[temp->data]++;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (m[0] > 0)
        {
            temp->data = 0;
            m[0]--;
        }
        else if (m[1] > 0)
        {
            temp->data = 1;
            m[1]--;
        }
        else if (m[2] > 0)
        {
            temp->data = 2;
            m[2]--;
        }
        temp = temp->next;
    }
    return head;
    // Add code here
}