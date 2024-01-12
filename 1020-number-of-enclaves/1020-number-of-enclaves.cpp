class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int row,int col){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1&&vis[nr][nc]==0){
                dfs(grid,vis,nr,nc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++){
            if(!vis[0][j]&&grid[0][j]==1){
                dfs(grid,vis,0,j);
            }
            if(!vis[n-1][j]&&grid[n-1][j]==1){
                dfs(grid,vis,n-1,j);
            }
            
        }
         for(int i=0;i<n;i++){
            if(!vis[i][0]&&grid[i][0]==1){
                dfs(grid,vis,i,0);
            }
            if(!vis[i][m-1]&&grid[i][m-1]==1){
                dfs(grid,vis,i,m-1);
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&vis[i][j]==0) ans++;
            }
        }
        return ans;
    }
};