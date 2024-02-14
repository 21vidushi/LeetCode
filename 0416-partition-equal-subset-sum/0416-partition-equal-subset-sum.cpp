class Solution {
public:
    bool find(vector<int>& nums,int k){
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=k){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                bool ntake= dp[i-1][j];
                bool take=false;
                if(nums[i]<=j){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=take|ntake;
            }
        }
        return dp[n-1][k];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        int s1=sum/2;
        bool ans=find(nums,s1);
        return ans;
    }
};