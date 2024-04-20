class Solution {
public:
    bool isSafe(int row,int col,vector<string> board,int n){
        int row1=row;
        int col1=col;
         while(row>=0&&col>=0){
            if(board[row][col]=='Q') return false;
            row--;
             col--;
        }
        row=row1;
        col=col1;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

       
        row=row1;
        col=col1;
        while(row<n&&col>=0){
             if(board[row][col]=='Q') return false;
             col--;
            row++;
        }
        return true;
    }
    void solve( vector<vector<string>> &ans,int n, int col,vector<string> &board){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,col,board,n)){
            board[i][col]='Q';
            solve(ans,n,col+1,board);
            board[i][col]='.';
        }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(ans,n,0,board);
        return ans;
    }
};