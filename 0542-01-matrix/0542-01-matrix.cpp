class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        int vis[n][m];
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
                else vis[i][j]=0;
            }
        }
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int step=q.front().first;
            q.pop();
            ans[r][c]=step;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=dc[i]+c;
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({step+1,{nr,nc}});
                }
            }
        }
        return ans; 
    }
};