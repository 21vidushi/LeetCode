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
    ListNode *  reverse(ListNode * head){
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        int mid=len/2;
        if(len%2==0) mid=mid-1;
        
        int cnt=0;
        temp=head;
        while(cnt<mid){
            temp=temp->next;
            cnt++;
        }
        ListNode * newhead=reverse(temp->next);
        temp=head;
        while(newhead!=NULL){
            if(newhead->val!=temp->val) return false;
            temp=temp->next;
            newhead=newhead->next;
        }
        
        return true;;
    }
};