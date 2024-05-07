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
       vector<int>before(n+1,0),curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int pick=0;
                int nott=before[prev+1];
                if(prev ==-1||nums[prev]<nums[i]){
                    pick=1+ before[i+1];
                }
                curr[prev+1]=max(pick,nott);
            }
            before=curr;
        }
        return before[0];
    }
};