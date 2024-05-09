class Solution {
public:
    int find(int i,int j,vector<int>&cuts, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            int cost= find(i,k-1,cuts,dp)+ find(k+1,j,cuts,dp)+ cuts[j+1]-cuts[i-1];
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int s=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(s+2,vector<int>(s+2,0));
        for(int i=s;i>=1;i--){
            for(int j=1;j<=s;j++){
                if(i>j) continue;
                int mini=INT_MAX;
                for(int k=i;k<=j;k++){
                int cost= dp[i][k-1]+dp[k+1][j]+ cuts[j+1]-cuts[i-1];
                    mini=min(mini,cost);
            }
                dp[i][j]=mini;
            }
        }
        return dp[1][s];
    }
};