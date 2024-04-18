class Solution {
public:
    int find(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        if(i+1<n) cnt+=grid[i+1][j];
        if(i-1>=0) cnt+=grid[i-1][j];
        if(j+1<m) cnt+=grid[i][j+1];
        if(j-1>=0) cnt+=grid[i][j-1];
        return cnt;
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]){
                perimeter+= 4-find(grid,i,j);
                }
            }
        }
        return perimeter;
    }
};