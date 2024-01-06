/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(!root) return "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL) ans.append("#,");
            else ans.append(to_string(front->val)+',');
            if(front!=NULL){
                q.push(front->left);
                q.push(front->right);
            }
            
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                front->left=NULL;
            }
            else{
                TreeNode* temp=new TreeNode(stoi(str));
                front->left=temp;
                q.push(temp);
            }
             getline(s,str,',');
            if(str=="#"){
                front->right=NULL;
            }
            else{
                TreeNode* temp1=new TreeNode(stoi(str));
                front->right=temp1;
                q.push(temp1);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));