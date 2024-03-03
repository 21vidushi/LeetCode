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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        if(head->next==NULL) return NULL;
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* deleted=NULL;
        int cnt=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len==n) return head->next;
        while(cnt<n){
            fast=fast->next;
            cnt++;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        if(slow->next!=NULL){
            slow->next=slow->next->next;
        }
        return head;
    }
};