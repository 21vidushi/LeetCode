/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL||head->next==NULL) return false;
        if(head->next==head) return true;
        while(fast!=NULL){
            if(fast->next!=NULL) fast=fast->next->next;
            else
            fast=fast->next;
            slow=slow->next;
           
            if(fast==slow) return true;
        }
        return false;
    }
};