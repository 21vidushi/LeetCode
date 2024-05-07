class Solution {
public:
    int find(int i,int buy,vector<int>&prices,int n, vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit;
        if(buy==0){
            profit=max(find(i+1,buy,prices,n,dp),-prices[i]+find(i+1,1,prices,n,dp));
        }
        if(buy==1){
            profit=max(find(i+1,buy,prices,n,dp),prices[i]+find(i+2,0,prices,n,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit;
                if(buy==0){
                    profit=max(dp[i+1][buy],-prices[i]+dp[i+1][1]);
                }
                if(buy==1){
                   
                        profit=max(dp[i+1][1],prices[i]+dp[i+2][0]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][0];
    }
};