class Solution {
public:
    void find(vector<int>& nums, vector<int>& temp,vector<int>&mpp,vector<vector<int>> &ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp); return;
        }
        for(int i=0;i<nums.size();i++){
            if(mpp[i]==0){
                temp.push_back(nums[i]);
                mpp[i]=1;
                find(nums,temp,mpp,ans);
                mpp[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>mpp(nums.size(),0);
        vector<int> temp;
        find(nums,temp,mpp,ans);
        return ans;
        
    }
};