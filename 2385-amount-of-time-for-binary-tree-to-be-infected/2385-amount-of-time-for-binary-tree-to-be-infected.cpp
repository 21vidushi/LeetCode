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
    
    void solve(TreeNode* root,int start,TreeNode*&Target){
        if(root==NULL) return;
        if(root->val==start) Target=root;
        solve(root->left,start,Target);
        solve(root->right,start,Target);
        
    }
    void createparent(map<TreeNode*,TreeNode*> &parent,TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front->left){
                q.push(front->left);
                parent[front->left]=front;
            }
            if(front->right){
                q.push(front->right);
                parent[front->right]=front;
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        TreeNode* target;
        solve(root,start,target);
        map<TreeNode*,bool> visited;
        map<TreeNode*,TreeNode*> parent;
        createparent(parent,root);
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            int n=q.size();
            bool flag=false;
            for(int i=0;i<n;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->left&&!visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                    flag=true;
                }
                if(front->right&&!visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                    flag=true;
                }
                if(parent[front]&&!visited[parent[front]]){
                    q.push(parent[front]);
                    visited[parent[front]]=true;
                    flag=true;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};