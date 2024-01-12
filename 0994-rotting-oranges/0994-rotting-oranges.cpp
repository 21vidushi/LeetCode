class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        int vis[n][m];
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=2;
                }
                else vis[i][j]=0;
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
           
            int r=q.front().second.first;
            int c=q.front().second.second;
            int t=q.front().first;
            q.pop();
             time=max(time,t);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]!=2&&grid[nr][nc]==1){
                    q.push({t+1,{nr,nc}});
                    vis[nr][nc]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2&&grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};