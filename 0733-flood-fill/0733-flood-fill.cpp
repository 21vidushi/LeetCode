class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> ans;
        ans=image;
        queue<pair<int,pair<int,int>>> q;
        q.push({ini,{sr,sc}});
        ans[sr][sc]=color;
        
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int col=q.front().first;
            q.pop();
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&ans[nr][nc]!=color &&image[nr][nc]==ini){
                    ans[nr][nc]=color;
                    q.push({color,{nr,nc}});
                }
            }
            
        }
        return ans;
    }
};