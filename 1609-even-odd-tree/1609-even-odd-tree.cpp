/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
       queue<TreeNode*> q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            int s=q.size();
            int prev=-1,prev1=1e9;
            for(int j=0;j<s;j++){
                if(i%2==0){
                    TreeNode* temp=q.front();
                    q.pop();
                    if(temp!=NULL){
                    if((temp->val%2)==0||(temp->val)<=prev){
                        return false;
                    }
                    prev=temp->val;
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                }
                }
                else{
                    TreeNode* temp=q.front();
                    q.pop();
                    int valu=temp->val;
                    if(valu%2!=0||valu>=prev1)
                        return false;
                    prev1=valu;
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                }
            }
            i++;
        }
        return true;
        
    }
};