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
    void createmap(map<int,int> &mpp,vector<int> inorder){
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int &index,int st,int en,map<int,int>& mpp){
        if(st>en||index<0) return NULL;
        int ele=postorder[index--];
        TreeNode* root= new TreeNode(ele);
        int pos=mpp[ele];
        root->right=solve(inorder,postorder,index,pos+1,en,mpp);
        root->left=solve(inorder,postorder,index,st,pos-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postindex=n-1;
        map<int,int> mpp;
        createmap(mpp,inorder);
        TreeNode* ans=solve(inorder,postorder,postindex,0,n-1,mpp);
        return ans;
    }
};