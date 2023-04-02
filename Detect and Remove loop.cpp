// link: https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=1


Node* startOfLoop(Node* head){

    Node* slow = head;

    Node* fast = head;

 

    while(fast && fast->next){

        slow = slow->next;

        fast = fast->next->next;

        if(slow == fast)    break;

    }

 

    // no loop

    if(fast==NULL || fast->next==NULL)  return NULL;

    

    // loop exists

    slow = head;

    while(slow != fast){

        slow = slow->next;

        fast = fast->next;

    }

 

    return slow;

}

 

Node *removeLoop(Node *head)

{

    if(head==NULL) return head;

 

    Node* startLoop = startOfLoop(head);

    if(startLoop==NULL)  return head;

 

    Node* temp = startLoop;

    while(temp->next != startLoop){

        temp = temp->next;

    }

 

    temp->next = NULL;

    return head;

}
