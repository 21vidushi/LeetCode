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
    bool check(TreeNode* root,long mini,long maxi){
        if(root==NULL) return true;
        if(root->val<=mini||root->val>=maxi) return false;
        bool lefti= check(root->left, mini,root->val);
        bool righti=check(root->right,root->val,maxi);
        return lefti&&righti;
    }
    bool isValidBST(TreeNode* root) {
        bool ans= check(root,LONG_MIN,LONG_MAX);
        return ans;
    }
};