class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& visited,int m,int n){
        visited[i][j]=1;
        if(i-1>=0&&grid[i][j]=='1'&&visited[i-1][j]==0){
            dfs(grid,i-1,j,visited,m,n);
        }
        if(i+1<m&&grid[i][j]=='1'&&visited[i+1][j]==0){
            dfs(grid,i+1,j,visited,m,n);
        }
        if(j-1>=0&&grid[i][j]=='1'&&visited[i][j-1]==0){
            dfs(grid,i,j-1,visited,m,n);
        }
        if(j+1<n&&grid[i][j]=='1'&&visited[i][j+1]==0){
            dfs(grid,i,j+1,visited,m,n);
        }
        else return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&visited[i][j]==0){
                    cnt++;
                    dfs(grid,i,j,visited,m,n);
                }
            }
        }
        return cnt;
    }
};