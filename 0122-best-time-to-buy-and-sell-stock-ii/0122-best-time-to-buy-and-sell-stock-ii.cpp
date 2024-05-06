class Solution {
public:
    int find(int i,int buy,vector<int>&prices,int n,vector<vector<int>>&dp){
        if(i==n-1){
            if(buy==1) return prices[n-1];
            else return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy==0){
            profit= max(profit,max(-prices[i]+ find(i+1,1,prices,n,dp),find(i+1,0,prices,n,dp)));
        }
        if(buy==1){
            profit=max(profit, max(prices[i]+find(i+1,0,prices,n,dp),find(i+1,1,prices,n,dp)));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return find(0,0,prices,n,dp);
    }
};