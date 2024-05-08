class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int> hash(n);
        int maxi=1;
        int hashindx=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0&&dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                hashindx=i;
            }
        }
        ans.push_back(nums[hashindx]);
        while(hashindx!=hash[hashindx]){
            hashindx=hash[hashindx];
            ans.push_back(nums[hashindx]);
        }
        // reverse(ans.begin(), ans.end());
       return ans;
    }
};