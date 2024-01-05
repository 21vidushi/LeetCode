class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        int l=1;    
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int indx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[indx]=nums[i];
            }
        }
        return ans.size();
    }
};