class Solution {
public:
    void find(int indx,int sum,int k,int n,vector<vector<int>>& ans,vector<int>& arr){
        if(sum==n&&k==0){
            ans.push_back(arr);
            return;
        }
        if(sum>n) return;
        if(k<0) return;
        for(int i=indx;i<=9;i++){
            if(i>n) break;
            arr.push_back(i);
            find(i+1,sum+i,k-1,n,ans,arr);
            arr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr;
       find(1,0,k,n,ans,arr);
        return ans;
    }
};