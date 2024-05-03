class Solution {
public:
    int find(int amount, vector<int>& coins,int i, vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(amount<0) return 0;
        if(i==0){
            if(amount%coins[i]==0) return 1;
            else return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=0;
        int nott=find(amount,coins,i-1,dp);
        if(coins[i]<=amount){
            pick=find(amount-coins[i],coins,i,dp);
        }
        return dp[i][amount]=pick+nott;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int t=1;t<=amount;t++){
            if(t%coins[0]==0) dp[0][t]=1;
        }
        for(int i=1;i<n;i++){
            for(int t=1;t<=amount;t++){
                int pick=0;
                int nott=dp[i-1][t];
                if(coins[i]<=t) pick=dp[i][t-coins[i]];
                dp[i][t]=pick+nott;
            }
        }
        
        return dp[n-1][amount];
    }
};