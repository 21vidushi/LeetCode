class Solution {
public:
    int find(vector<int>& nums, int target){
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        if(nums[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        
        if(nums[0]!=0&&nums[0]<=target) dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int t=0;t<=target;t++){
                int nott=dp[i-1][t];
                int pick=0;
                if(nums[i]<=t) pick= dp[i-1][t-nums[i]];
                dp[i][t]=pick+nott;
            }
        }
        return dp[n-1][target];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totsum=0;
        for(int i=0;i<nums.size();i++){
            totsum+=nums[i];
        }
        int diff=totsum-target;
        if(diff<0||diff%2!=0) return 0;
        int S1= diff/2;
        
        return find(nums,S1);
    }
};