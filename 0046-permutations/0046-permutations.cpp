class Solution {
public:
    void find(vector<int>& nums, vector<int>& temp,vector<vector<int>> &ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp); return;
        }
        for(int i=0;i<nums.size();i++){
            if(::find(temp.begin(),temp.end(),nums[i])==temp.end()){
                temp.push_back(nums[i]);
                find(nums,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        find(nums,temp,ans);
        return ans;
        
    }
};