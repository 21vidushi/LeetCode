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
    ListNode* removeNodes(ListNode* head) {
        vector<int>arr,ans;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        vector<int> maxi(n);
        int maxim=-1;
        for(int i=n-1;i>=0;i--){
            if(maxim<arr[i]){
                maxim=arr[i];
            }
            maxi[i]=maxim;
        }
        for(int i=0;i<n;i++){
            if(arr[i]>=maxi[i]) ans.push_back(arr[i]);
        }
        temp=head;
        ListNode* prev=temp;
        for(int i=0;i<ans.size();i++){
            prev=temp;
            temp->val=ans[i];
            temp=temp->next;
        }
        prev->next=NULL;
        return head;
        
    }
};