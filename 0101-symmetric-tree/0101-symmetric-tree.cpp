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
     bool check(TreeNode *root1,TreeNode* root2){
        if(root1==NULL&&root2==NULL) return true;
         if(root1==NULL||root2==NULL) return false;
        if(root1->val!=root2->val) return false;
        bool left=check(root1->left,root2->right);
        bool right=check(root2->left,root1->right);
        return left&&right;

    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
       bool ans= check(root->left,root->right);
       return ans;

    }
};