#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};

struct node *reverse(struct node *head, int k)
{
    node *curr = head;
    node *prev = NULL;
    node *aage;
    for (int i = 0; i < k && curr; ++i)
    {
        aage = curr->next;
        curr->next = prev;
        prev = curr;
        curr = aage;
    }
    if (aage)
    {
        head->next = reverse(aage, k);
    }
    return prev;
}