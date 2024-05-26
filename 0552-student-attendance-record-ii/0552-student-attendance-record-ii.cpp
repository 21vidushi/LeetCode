class Solution {
public:
    int mod=1000000007;
    long long find(int i, int ac, int clc,vector<vector<vector<int>>>&dp){
        if(i==0) return 1;
        if(dp[i][ac][clc]!=-1) return dp[i][ac][clc];
        long long ans=0;
        ans=  find(i-1,ac,0,dp)%mod;
        if(ac<1) ans+=  find(i-1,ac+1,0,dp)% mod;
        if(clc<2)  ans+= find(i-1,ac,clc+1,dp)% mod;
        return dp[i][ac][clc]= ans%mod;
        
    }
    int checkRecord(int n) {
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return int(find(n,0,0,dp));
    }
};