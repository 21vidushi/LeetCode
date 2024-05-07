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
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return find(nums,n,0,-1,dp);
    }
};