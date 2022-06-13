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
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow = head;
    Node *fast = head;
    *head1_ref = head;
    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next != head)
        fast = fast->next;
    fast->next = slow->next;
    *head2_ref = slow->next;
    slow->next = *head1_ref;
}