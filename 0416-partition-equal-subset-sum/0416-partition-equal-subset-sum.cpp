class Solution {
public:
    bool find(vector<int>& nums,int k){
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=k){
        dp[0][nums[0]]=true; }
        for(int i=1;i<n;i++){
            for(int t=1;t<=k;t++){
                int pick=false;
                if(nums[i]<=t) pick=dp[i-1][t-nums[i]];
            
            int nott=dp[i-1][t];
            dp[i][t]= pick|nott;
        }
        }
        return dp[n-1][k];
    }
    bool canPartition(vector<int>& nums) {
        int totsum=0;
        for(int i=0;i<nums.size();i++){
            totsum+=nums[i];
        }
        if(totsum%2) return false;
        else return find(nums,totsum/2);
    }
};