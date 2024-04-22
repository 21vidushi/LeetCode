class Solution {
public:
    int find(int i,vector<int>&dp){
        if(i<=1) return 1;
        if(dp[i]!=-1) return dp[i];
        
        return dp[i]=find(i-1,dp)+find(i-2,dp);
    }
    int climbStairs(int n) {
        
        vector<int>dp(n+1,-1);
        return find(n,dp);
        
      
    }
};