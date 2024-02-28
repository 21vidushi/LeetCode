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
    int find(ListNode* &head){
        ListNode*temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(head==NULL||head->next==NULL) return head;
        int len=find(head);
        if(len<k) return head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* curr=NULL;
        int cnt=0;
        while(cnt<k){
            curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
            cnt++;
        }
        if(temp!=NULL){
            head->next=reverseKGroup(temp,k);
        }
        return prev;
        
    }
};
