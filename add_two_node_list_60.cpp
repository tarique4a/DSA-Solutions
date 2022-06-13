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
 Node* rev(Node* head)
    {
        Node* curr=head;
        Node* prev=NULL;
        Node* frd;
        while(curr)
        {
            frd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=frd;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       Node *one=rev(first);
       Node *two=rev(second);
       Node *head=NULL;
       int cry=0,val=0;
       while(one && two)
       {
           val=one->data+two->data+cry;
           cry=val/10;
           Node* temp=new Node(val%10);
           if(head==NULL)
           {
               head=temp;
           }
           else{
               temp->next=head;
               head=temp;
           }
           one=one->next;
           two=two->next;
       }
       while(one)
       {
           val=one->data+cry;
           cry=val/10;
            Node* temp=new Node(val%10);
           if(head==NULL)
           {
               head=temp;
           }
           else{
               temp->next=head;
               head=temp;
           }
           one=one->next;
       }
       while(two)
       {
           val=two->data+cry;
           cry=val/10;
            Node* temp=new Node(val%10);
           if(head==NULL)
           {
               head=temp;
           }
           else{
               temp->next=head;
               head=temp;
           }
           two=two->next;
       }
       while(cry!=0)
       {
            Node* temp=new Node(1);
           if(head==NULL)
           {
               head=temp;
           }
           else{
               temp->next=head;
               head=temp;
           }
           cry=0;
       }
      return head;
    }