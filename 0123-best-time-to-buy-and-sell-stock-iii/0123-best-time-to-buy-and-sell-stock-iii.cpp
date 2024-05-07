class Solution {
public:
    int find(int i,int buy,int cap,vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
        if(cap==0||i==n) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        long profit;
        if(buy==0){
            profit=max(find(i+1,0,cap,prices,n,dp),-prices[i]+find(i+1,1,cap,prices,n,dp));
        }
        if(buy==1){
            profit=max(find(i+1,1,cap,prices,n,dp),prices[i]+find(i+1,0,cap-1,prices,n,dp));
        }
        return dp[i][buy][cap]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return find(0,0,2,prices,n,dp);
    }
};