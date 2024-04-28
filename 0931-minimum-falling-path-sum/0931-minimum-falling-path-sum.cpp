class Solution {
public:
    int find(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
         if(j<0||j>=matrix.size()) return 1e6;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up= matrix[i][j]+ find(i-1,j,matrix,dp);
        int rd= matrix[i][j]+find(i-1,j+1,matrix,dp);
        int ld= matrix[i][j]+find(i-1,j-1,matrix,dp);
        return dp[i][j]=min(ld,min(rd,up));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int mini=INT_MAX;
         int n=matrix.size();
        vector<int>prev(n,0);
         for(int j=0;j<n;j++){
             prev[j]=matrix[0][j];
         }
        for(int i=1;i<n;i++){
            int mini=INT_MAX;
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+prev[j];
                int rd=1e6,ld=1e6;
                if(j-1>=0) ld=matrix[i][j]+prev[j-1];
                if(j+1<n) rd=matrix[i][j]+prev[j+1];
                mini=min(ld,min(rd,up));
                curr[j]=mini;
            }
            prev=curr;
        }
        
        
        for(int i=0;i<n;i++){
            mini=min(mini,prev[i]);
        }
        return mini;
    }
};