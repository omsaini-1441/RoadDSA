// Link - https://leetcode.com/problems/reverse-linked-list/
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev =NULL;
        ListNode* curr = head;
        
        while(curr){
            ListNode* fwd = curr->next;
            curr->next = prev;
            prev= curr;
            curr= fwd;
        }
        return prev;
    }
};

// recursive way 1
// call recursion for chotaHead just to find and place head pointer to last element and then coming back from there only and deal with first element later
// by changing head(first ele)->next->next(choti list ka last ele i.e doosra ele) = head and head->next = NULL;
Node* reverse1(Node* head){
    // base case
    if(head==NULL || head->next== NULL){
        return head;
    }
    Node* ChotaHead = reverse1(head->next);
        head->next->next=head;
        head->next =NULL;
    return chotaHead;
}
