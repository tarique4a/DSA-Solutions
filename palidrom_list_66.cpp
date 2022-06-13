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
Node *reverse(Node *rev)
{
    Node *cur = rev;
    Node *prv = NULL;
    while (cur != NULL)
    {
        Node *next = cur->next;
        cur->next = prv;
        prv = cur;
        cur = next;
    }
    return prv;
}
// Function to check whether the list is palindrome.
bool isPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *rev = reverse(slow->next);
    Node *temp = head;
    while (rev != NULL)
    {
        if (temp->data != rev->data)
            return false;

        temp = temp->next;
        rev = rev->next;
    }
    return true;
}