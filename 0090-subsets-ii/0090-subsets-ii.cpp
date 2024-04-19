class Solution {
public:
    void find(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int> &temp) {
       
            ans.push_back(temp);
       
        for(int j=i;j<nums.size();j++){
            if(j!=i&&nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            find(nums,j+1,ans,temp);
            temp.pop_back();
            
            
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        find(nums, 0, ans, temp);
        return ans;
    }
};
