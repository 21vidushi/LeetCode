class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxans=nums[0];
        int dp[n];
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=nums[i]+ (dp[i-1]>0?dp[i-1]:0);
            maxans=max(maxans,dp[i]);
        }
        return maxans;
    }
};