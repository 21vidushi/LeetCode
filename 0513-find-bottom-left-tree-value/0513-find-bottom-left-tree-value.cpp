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
    int find(TreeNode* root){
        if(root==NULL) return 0;
        int lh=find(root->left);
        int rh=find(root->right);
        return 1+(max(lh,rh));
    }
    void inorder(TreeNode* root,vector<int>&ans,int level,int l){
        if(root==NULL) return;
        if(level==l){
            ans.push_back(root->val);
        }
        inorder(root->left,ans,level,l+1);
        inorder(root->right,ans,level,l+1);
        
        
        
    }
    int findBottomLeftValue(TreeNode* root) {
        int height= find(root);
        int level=height-1;
        vector<int> ans;
        inorder(root,ans,level,0);
        return ans.front();
        
    }
};