class Solution {
public:
    int find(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            int coins= find(i,k-1,nums,dp)+ find(k+1,j,nums,dp)+ nums[k]*nums[i-1]*nums[j+1];
            maxi=max(maxi,coins);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return find(1,n,nums,dp);
    }
};