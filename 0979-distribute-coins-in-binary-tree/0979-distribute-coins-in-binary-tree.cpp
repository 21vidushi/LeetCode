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
    int ans=0;
    int find(TreeNode* root){
        if(root==NULL) return 0;
        int l=find(root->left);
        int r=find(root->right);
        ans+=abs(l)+abs(r);
        return (l+r+root->val-1);
    }
    int distributeCoins(TreeNode* root) {
        find(root);
        return ans;
    }
};