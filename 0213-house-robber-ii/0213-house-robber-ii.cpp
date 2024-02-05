class Solution {
public:
    int check(vector<int> & num){
        int n=num.size();
        int dp[n];
        dp[0]=num[0];
        for(int i=1;i<n;i++){
            int ss=dp[i-1];
            int fs=num[i];
            if(i>1){
                fs+=dp[i-2];
            }
            dp[i]=max(fs,ss);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(check(temp1),check(temp2));
    }
};