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
    void solve(TreeNode* root,int k,vector<int>& ans){
        if(root==NULL||ans.size()>k) return;
        solve(root->left,k,ans);
        if(ans.size()<k) ans.push_back(root->val);
        solve(root->right,k,ans);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        solve(root,k,ans);
        return ans.back();
    }
};