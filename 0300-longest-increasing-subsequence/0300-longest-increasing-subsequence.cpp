class Solution {
public:
    int find(vector<int>&nums,int n,int i,int prev, vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int pick=0;
        int nott=find(nums,n,i+1,prev,dp);
        if(prev==-1||nums[prev]<nums[i]){
            pick=1+ find(nums,n,i+1,i,dp);
        }
        return dp[i][prev+1]=max(pick,nott);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int pick=0;
                int nott=dp[i+1][prev+1];
                if(prev ==-1||nums[prev]<nums[i]){
                    pick=1+ dp[i+1][i+1];
                }
                dp[i][prev+1]=max(pick,nott);
            }
        }
        return dp[0][0];
    }
};