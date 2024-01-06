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
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int &index,int st,int en,map<int,int>& mpp,int n){
        if(st>en||index>=n) return NULL;
        int ele=preorder[index++];
        TreeNode* root= new TreeNode(ele);
        int pos=mpp[ele];
        root->left=solve(inorder,preorder,index,st,pos-1,mpp,n);
        root->right=solve(inorder,preorder,index,pos+1,en,mpp,n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int preindex=0;
        map<int,int> mpp;
        createmap(mpp,inorder);
        TreeNode* ans=solve(inorder,preorder,preindex,0,n-1,mpp,n);
        return ans;
    }
};