/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
                    //BRUTE FORCE
class Solution {
    private:
int getLength(ListNode* head){
    int len=0;
    while(head!= NULL){
        len++;
        head=head->next;
    }
    return len;
}
public:
    ListNode* middleNode(ListNode* head) {
        int len = getLength( head);
        int ans =(len/2);

        ListNode* temp= head;
        int cnt=0;
        while(cnt<ans){
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
};

        // FAST - SLOW POINTER APPROACH

class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
