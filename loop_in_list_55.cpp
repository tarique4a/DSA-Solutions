#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
 bool detectLoop(node* head)
    {
        node* slow=head;
        node* fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return true;
        }
        return false;
    }