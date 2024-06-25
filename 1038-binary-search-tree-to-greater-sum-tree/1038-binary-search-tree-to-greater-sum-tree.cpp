void dos(int &sumtillnow,TreeNode*root)
 {
    if(root == NULL)
    {
        return;
    }
    dos(sumtillnow,root->right);
    if(sumtillnow == INT_MIN)
    {
        sumtillnow=root->val;
        root->val = sumtillnow;
    }
    else{
    sumtillnow+=root->val;
    root->val = sumtillnow;
    }
    dos(sumtillnow,root->left);
 }
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sumtillnow = INT_MIN;
        dos(sumtillnow,root);
        return root;
    }
};