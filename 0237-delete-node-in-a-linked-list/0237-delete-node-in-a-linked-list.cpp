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
    void deleteNode(ListNode* node) {
        ListNode* temp=node;
        ListNode* prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp->val=temp->next->val;
            temp=temp->next;
        }
        prev->next=NULL;
        
    }
};