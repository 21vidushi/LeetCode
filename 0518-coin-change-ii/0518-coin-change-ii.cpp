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
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return find(amount,coins,n-1,dp);
    }
};