class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                double match=0,nott=0;
                if(s[i-1]==t[j-1]) match=dp[i-1][j-1] +dp[i-1][j];
                else nott= dp[i-1][j];
                dp[i][j]=match+nott;
            }
        }
        
        return int(dp[n][m]);
        
    }
};
