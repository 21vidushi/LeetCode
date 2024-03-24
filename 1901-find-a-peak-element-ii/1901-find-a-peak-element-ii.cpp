class Solution {
public:
    int find(vector<vector<int>>& mat,int n,int m,int col){
        int index=-1;
        int maxele=INT_MIN;
        for(int i=0;i<m;i++){
            if(mat[i][col]>maxele){
                maxele=mat[i][col];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low +(high-low)/2;
            int maxrow= find(mat,n,m,mid);
            int left= mid-1>=0? mat[maxrow][mid-1]:-1;
            int right= mid+1<n?mat[maxrow][mid+1]:-1;
            if(mat[maxrow][mid]>left&&mat[maxrow][mid]>right){
                return {maxrow,mid};
            }
            else if(mat[maxrow][mid]<left){
                high=mid-1;
            }
            else low=mid+1;
        }
        return {-1,-1};
    }
};