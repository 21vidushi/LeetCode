class Solution {
public:
    bool Valid(int i,int j, vector<vector<int>>&vis){
        int n=vis.size();
        if(i<0||j<0||i>=n||j>=n||vis[i][j]==1) return false;
        else return true;
    }
    bool isSafe(int safef,vector<vector<int>> &theifdistance,vector<vector<int>>& grid){
         int n=grid.size();
         queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        q.push({0,0});
         if(theifdistance[0][0]<safef) return false;
        vis[0][0]=1;
        while(!q.empty()){
            int cr=q.front().first;
            int cc= q.front().second;
            q.pop();
            if(cr==n-1&&cc==n-1) return true;
            for(int i=0;i<4;i++){
                int nr=cr-row[i];
                int nc=cc-col[i];
                if(Valid(nr,nc,vis)){
                    if(theifdistance[nr][nc]<safef) continue;
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
           
            
        }
        return false;
    }
    vector<int> row{0,0,-1,+1};
    vector<int> col{-1,+1,0,0};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>> theifdistance(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                } 
            }
        }
        int len=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
            int currrow= q.front().first;
            int currcol=q.front().second;
            theifdistance[currrow][currcol]=len;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=currrow-row[i];
                int newc= currcol-col[i];
                if(!Valid(newr,newc,vis)) continue;
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                
            }    
                
            
        }
            len++;
        }
        int low=0,high=len;
        int ans=0;
        while(low<=high){
            int mid=(low)+(high-low)/2;
            if(isSafe(mid,theifdistance,grid)){
                low=mid+1;
                ans=mid;
            }
            else high=mid-1;
        }
        return ans;
    }
};