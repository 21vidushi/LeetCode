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
        ListNode *temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len==1) return NULL;
        if(len==n){
            return head->next;
        }
        int traverse=len-n;
        int cnt=0;
        temp=head;
        while(cnt<traverse-1){
            temp=temp->next;
            cnt++;
        }
        temp->next=temp->next->next;
        return head;
        
    }
};