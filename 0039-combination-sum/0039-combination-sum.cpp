class Solution {
public:
    void find(vector<int>& candidates, int target,int sum,vector<vector<int>> &ans,int i,int n,vector<int> temp){
        if(i>n) return;
        if(i==n){
            if(sum==target){
                ans.push_back(temp);
                return;
            }
            else return;
        }
        if(sum>target) return;
        temp.push_back(candidates[i]);
        find(candidates,target,sum+candidates[i],ans,i,n,temp);
        temp.pop_back();
        find(candidates,target,sum,ans,i+1,n,temp);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        int sum=0;
        vector<int> temp;
        find(candidates,target,sum,ans,0,n,temp);
        return ans;
    }
};