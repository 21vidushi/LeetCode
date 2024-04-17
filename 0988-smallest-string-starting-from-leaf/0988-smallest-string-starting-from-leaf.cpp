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
    void find(TreeNode* root, vector<string>& store,string temp){
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL){
            temp+=('a'+root->val);
            reverse(temp.begin(),temp.end());
            store.push_back(temp);
            return;
        }
        char chara=char('a'+root->val);
        find(root->left,store,temp+chara);
        find(root->right,store,temp+chara);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> store;
        find(root,store,"");
         sort(store.begin(),store.end());
         return store[0];
    }
};