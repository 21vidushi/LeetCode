class Solution {
public:
    int find(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(i==0){
            if(amount%coins[0]==0) return amount/coins[0];
            else return INT_MAX;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=INT_MAX;
        int nott=find(coins,i-1,amount,dp);
        if(coins[i]<=amount){
            pick=1+find(coins,i,amount-coins[i],dp);
        }
        return dp[i][amount]=min(pick,nott);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int a=1;a<=amount;a++){
            if(a%coins[0]==0) dp[0][a]=a/coins[0];
            else dp[0][a]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int a=1;a<=amount;a++){
                int pick=1e9;
                int nott=dp[i-1][a];
                if(coins[i]<=a){
                    pick=1+dp[i][a-coins[i]];
                }
                dp[i][a]=min(pick,nott);
            }
        }
        
        int ans= dp[n-1][amount];
        if(ans>=1e9) return -1;
        else return ans;
    }
};