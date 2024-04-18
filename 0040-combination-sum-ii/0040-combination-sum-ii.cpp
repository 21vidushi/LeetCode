class Solution {
public:
    void find(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int>&temp,int indx){
      
           if(target==0){  ans.push_back(temp); 
           return;
       }
       for(int i=indx;i<candidates.size();i++ ){
           if(i>indx&&candidates[i]==candidates[i-1]) continue;
           if(candidates[i]>target) return;
           temp.push_back(candidates[i]);
           find(candidates,target-candidates[i],ans,temp,i+1);
           temp.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        find(candidates,target,ans,temp,0);
        return ans;
    }
};