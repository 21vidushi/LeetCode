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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* newhead= reverse(head);
        ListNode* temp=newhead;
        ListNode* ans=temp;
        ListNode* prev=temp;
        int carry=0;
        while(temp!=NULL){
            if(temp!=NULL){
                prev=temp;
                int product= temp->val*2 + carry;
                temp->val=product%10;
                carry=product/10;
                 temp=temp->next;
            }
        }
        if(carry!=0){
                 ListNode* newn=new ListNode(carry);
                 prev->next=newn;
                prev=prev->next;
        }
        ListNode* res= reverse(ans);
        return res;
    }
};