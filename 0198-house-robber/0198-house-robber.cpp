class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int ss=0+dp[i-1];
            int fs=nums[i];
            if(i>1){
             fs+= dp[i-2]; }
            dp[i]=max(fs,ss);
        }
        return dp[n-1];
    }
};