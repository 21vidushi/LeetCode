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
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    long profit;
                    if(buy==0){
                        profit=max(dp[i+1][buy][cap],-prices[i]+dp[i+1][1][cap]);
                    }
                    if(buy==1){
                        profit=max(dp[i+1][buy][cap],prices[i]+dp[i+1][0][cap-1]);
                    }
                    dp[i][buy][cap]=profit;
                }
            }
        }
        
        return dp[0][0][2];
    }
};