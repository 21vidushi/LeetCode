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
        ListNode * fast=head;
        ListNode * slow=head;
        int cnt=0;
        while(cnt!=n){
            fast=fast->next;
            cnt++;
        }
        if(fast==NULL) return head->next;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};