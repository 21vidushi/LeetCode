/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark(TreeNode* root,map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front=q.front(); q.pop();
            if(front->left){
                parent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                parent[front->right]=front;
                q.push(front->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*,TreeNode*> parent;
        mark(root,parent);
        queue<TreeNode*>q;
        map<TreeNode*,bool> visited;
        q.push(target);
        visited[target]=true;
        int dis=0;
        while(!q.empty()){
            int s=q.size();
            if(dis==k) break;
            for(int i=0;i<s;i++){
            TreeNode* temp=q.front();
                q.pop();
            if(temp->left&&!visited[temp->left]){
                q.push(temp->left);
                visited[temp->left]=true;
            }
                if(temp->right&&!visited[temp->right]){
                q.push(temp->right);
                visited[temp->right]=true;
            }
              if(parent[temp]&&!visited[parent[temp]])  {
                  q.push(parent[temp]);
                  visited[parent[temp]]=true;
              }
                
            }
            dis++;
            
            
            
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};