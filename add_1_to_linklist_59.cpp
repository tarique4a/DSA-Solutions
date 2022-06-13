#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
 Node* rev(Node * head)
    {
        Node* curr=head;
        Node* aage=NULL;
        Node* prev=NULL;
        while(curr)
        {
            aage=curr->next;
            curr->next=prev;
            prev=curr;
            curr=aage;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        Node* curr=rev(head);
        Node* ret=curr;
        Node* prev=curr;
        curr->data=curr->data+1;
        int cry=curr->data/10;
        curr->data=curr->data%10;
        curr=curr->next;
        while(cry>0 && curr)
        {
            int val=curr->data+cry;
            cry=val/10;
            curr->data=val%10;
            prev=curr;
            curr=curr->next;
            
        }
         if (cry != 0)
        {
            Node *extra = new Node(1);
            prev->next = extra;
        }
        ret=rev(ret);
        return ret;
       
        
    }