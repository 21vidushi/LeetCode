class Solution {
public:
    // int solve(vector<int>& nums,int i ,vector<int>&dp){
    //     if(i<0) return 0;
    //     if(i==0) return nums[0];
    //     if(dp[i]!=-1) return dp[i];
    //     int pick= nums[i]+solve(nums,i-2,dp);
    //     int nott= solve(nums,i-1,dp);
    //     return dp[i]=max(pick,nott);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
       vector<int>dp(n,0);
        int prev=nums[0];
        int prev1=0;
        if(n>1){
         prev1=max(nums[0],nums[1]); }
        for(int i=2;i<n;i++){
            
            int pick= nums[i]+prev; 
            int nott= prev1;
            int curr=max(pick,nott);
            prev=prev1;
            prev1=curr;
        }
       if(n==1) return prev;
        else return prev1;
    }
};