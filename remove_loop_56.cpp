#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
 bool Loop(Node* head)
    {
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return true;
        }
        return false;
    }
    void removeLoop(Node* head)
    {
        bool flag=Loop(head);
        if(flag==false) return;
        // code here
        // just remove the loop without losing any nodes
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        while(true)
        {
            if(fast->next==slow)
            {
                fast->next=NULL;
                return;
            }
            fast=fast->next;
        }
    }