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
    void find(TreeNode* &root,int val,int depth,int d){
        if(root==nullptr) return;
        if(d==depth-1){
            root->left= new TreeNode(val,root->left,nullptr);
            root->right= new TreeNode(val,nullptr,root->right);
            return;
        }
        d++;
        find(root->left,val,depth,d);
        find(root->right,val,depth,d);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int d=1;
        if(depth==1){
            TreeNode* newnode= new TreeNode(val,root,nullptr);
            return newnode;
        }
        find(root,val,depth,d);
        return root;
    }
};