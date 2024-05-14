class Solution {
public:
    void find(vector<vector<int>>& grid, vector<vector<int>>&vis,int i,int j,int &ans,int sum,int m,int n){
        if(i<0||i>=m||j<0||j>=n) return;
        if(grid[i][j]==0) return;
        if(vis[i][j]==0){
            vis[i][j]=1;
        sum+=grid[i][j];
        ans=max(ans,sum);
             find(grid,vis,i+1,j,ans,sum,m,n);
             find(grid,vis,i-1,j,ans,sum,m,n);
             find(grid,vis,i,j+1,ans,sum,m,n);
             find(grid,vis,i,j-1,ans,sum,m,n);
             sum-=grid[i][j];
            vis[i][j]=0;
            }
        else return;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<int>>vis(m,vector<int>(n,0));
                find(grid,vis,i,j,ans,sum,m,n);
            }
        }
        
        return ans;
    }
};