class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
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
        return dp[0][0][k];
    }
};