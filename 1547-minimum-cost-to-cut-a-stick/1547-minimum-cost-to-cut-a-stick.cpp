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
        vector<vector<int>>dp(s+1,vector<int>(s+1,-1));
        return find(1,s,cuts,dp);
    }
};