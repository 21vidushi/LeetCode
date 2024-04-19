class Solution {
public:
    void find(vector<int>& nums, vector<int>& temp,vector<vector<int>> &ans,int indx){
        if(indx==nums.size()){
            ans.push_back(temp); return;
        }
        for(int i=indx;i<nums.size();i++){
             swap(temp[i],temp[indx]);
            find(nums,temp,ans,indx+1);
            swap(temp[i],temp[indx]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp=nums;
        find(nums,temp,ans,0);
        return ans;
        
    }
};