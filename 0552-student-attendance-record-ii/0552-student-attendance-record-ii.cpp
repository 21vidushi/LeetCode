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
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ac=0;ac<=1;ac++){
            for(int clc=0;clc<=2;clc++){
                dp[0][ac][clc]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int ac=0;ac<=1;ac++){
                for(int clc=0;clc<=2;clc++){
                    long long ans=0;
                    ans= dp[i-1][ac][0];
                    if(ac<1) ans+=dp[i-1][ac+1][0];
                    if(clc<2) ans+=dp[i-1][ac][clc+1];
                    dp[i][ac][clc]= ans%mod;
                    
                }
            }
        }
        return dp[n][0][0];
    }
};