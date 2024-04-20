class Solution {
public:
    void solve( vector<vector<string>> &ans,int n, int col,vector<string> &board,vector<int>&row,vector<int>& lowerD,vector<int> &upperD){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(row[i]==0&&lowerD[i+col]==0&&upperD[n-1+col-i]==0){
            board[i][col]='Q';
            row[i]=1;
            lowerD[i+col]=1;
            upperD[n-1+col-i]=1;
            solve(ans,n,col+1,board,row,lowerD,upperD);
            board[i][col]='.';
             row[i]=0;
            lowerD[i+col]=0;
            upperD[n-1+col-i]=0;
            }
            
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<int> row(n,0);
        vector<int> lowerD(2*n-1,0);
         vector<int> upperD(2*n-1,0);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(ans,n,0,board,row,lowerD,upperD);
        return ans;
    }
};