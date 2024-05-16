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
    bool func(TreeNode* root){
        if(root->left==NULL&&root->right==NULL) return root->val;
       else if(root->val==2){
            return func(root->left)| func(root->right);
        }
       else{
            return func(root->left)& func(root->right);
        }
        
    }
    bool evaluateTree(TreeNode* root) {
        return func(root);
    }
};