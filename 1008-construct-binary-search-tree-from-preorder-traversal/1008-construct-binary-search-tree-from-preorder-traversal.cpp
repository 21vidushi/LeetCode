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
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder,int ins, int ine,int &index,int n){
        if(ins>ine||index>=n) return NULL;
        int ele=preorder[index++];
        TreeNode* root=new TreeNode(ele);
        int pos=0;
        for(int i=ins;i<=ine;i++){
            if(inorder[i]==ele){
                pos=i;
                break;
            }
        }
        root->left=solve(preorder,inorder,ins,pos-1,index,n);
        root->right=solve(preorder,inorder,pos+1,ine,index,n);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector <int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        int n=inorder.size();
        int pre=0;
        TreeNode* root=solve(preorder,inorder,0,n-1,pre,n);
        return root;
    }
};