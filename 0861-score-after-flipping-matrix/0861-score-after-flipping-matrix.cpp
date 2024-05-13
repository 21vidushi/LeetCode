class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        ans+=(m*(1<<(n-1)));
        for(int i=1;i<n;i++){
            int colcount=0;
            for(int j=0;j<m;j++){
                if(grid[j][0]==0) colcount+= grid[j][i]^1;
                else colcount+=grid[j][i];
            }
             if(m-colcount<colcount) ans+=(colcount*(1<<(n-i-1)));
            else ans+=(m-colcount)*(1<<(n-i-1));
           
        }
        return ans;
    }
};