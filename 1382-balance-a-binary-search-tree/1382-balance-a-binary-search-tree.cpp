class Solution {
public:
    vector<int> arr;
    void makeArr(TreeNode* r){
        if(!r) return;
        makeArr(r->left);
        arr.push_back(r->val);
        makeArr(r->right);
    }

    TreeNode* f(vector<int>& arr, int l, int r){
        if(l>r) return NULL;
        if(l==r){
            return new TreeNode(arr[l]);
        }
        
        int m = l + (r-l)/2;

        auto n = new TreeNode(arr[m]);

        n->left = f(arr, l, m-1);
        n->right = f(arr, m+1, r);

        return n;
    }


    TreeNode* balanceBST(TreeNode* root) {
        makeArr(root);

        return f(arr, 0, arr.size()-1);
    }
};