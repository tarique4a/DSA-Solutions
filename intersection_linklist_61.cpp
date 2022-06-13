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
Node *rev(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *frd;
    while (curr)
    {
        frd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frd;
    }
    return prev;
}

Node *findIntersection(Node *head1, Node *head2)
{
    Node *head = NULL;
    while (head1 && head2)
    {
        if (head1->data == head2->data)
        {
            Node *temp = new Node(head1->data);
            if (head == NULL)
            {
                head = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data > head2->data)
        {
            head2 = head2->next;
        }
        else
        {
            head1 = head1->next;
        }
    }
    head = rev(head);
    return head;
}