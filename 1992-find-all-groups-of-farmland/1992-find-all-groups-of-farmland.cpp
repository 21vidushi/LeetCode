class Solution {
public:
    void find(vector<vector<int>>& land, vector<vector<int>>& vis,int i,int j, vector<int>&large,vector<int>&small,int m,int n){
      if (i < 0 || i >= m || j < 0 || j >= n || !land[i][j] || vis[i][j]) return;
        
        vis[i][j] = 1;
        
        if (i < small[0] || (i == small[0] && j < small[1])) small = {i, j};
        if (i > large[0] || (i == large[0] && j > large[1])) large = {i, j};
        
        find(land, vis, i - 1, j, large, small, m, n); // up
        find(land, vis, i + 1, j, large, small, m, n); // down
        find(land, vis, i, j - 1, large, small, m, n); // left
        find(land, vis, i, j + 1, large, small, m, n); // right
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size();
        int n=land[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]&&vis[i][j]==0){
                     vector<int> small{INT_MAX,INT_MAX};
                     vector<int> large{-1,-1};
                    find(land,vis,i,j,large,small,m,n);
                    if(small[0]!=INT_MAX&&small[1]!=INT_MAX&&large[0]!=-1&&large[0]!=-1)
                        ans.push_back({small[0],small[1],large[0],large[1]});
                   
                }
            }
        }
        
        return ans;
    }
};