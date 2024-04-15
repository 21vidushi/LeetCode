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
    void find(TreeNode* root, vector<int>&store,string ans){
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL){
            string chara= to_string(root->val);
            ans+=chara;
            store.push_back(stoi(ans));
            return;
        }
        string chara= to_string(root->val);
         ans+=chara;
        find(root->left,store,ans);
        find(root->right,store,ans);
    }
    int sumNumbers(TreeNode* root) {
        int res=0;
        if(root==NULL) return root->val;
        string ans="";
        vector<int> store;
        find(root,store,ans);
        for(int i=0;i<store.size();i++){
            res+=store[i];
            cout<<store[i]<<" ";
        }
        
        return res;
    }
};