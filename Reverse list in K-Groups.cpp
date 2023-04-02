// link : https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=1


#include <bits/stdc++.h> 
/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

Node* kReverse(Node* head, int k) {

    // reverse 1 smaller problem i.e solve one group 

      int count=0;

       Node* prev=NULL,*curr=head,*nxt;

       while(curr && count<k){

           nxt=curr->next;

           curr->next=prev;

           prev=curr;  curr=nxt;   count++;

       }
// let the recursion  reverse rest of k groups for you
       if(nxt)

           head->next=kReverse(nxt,k);      //attack whatever recursion will give to head ka next

       return prev;

}

