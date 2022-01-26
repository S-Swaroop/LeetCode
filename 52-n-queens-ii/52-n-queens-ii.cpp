class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board(n , string(n , '.')) ;
        return dp(board , 0) ; 
    }
private: 
    bool check(vector<string> &board, int row, int col){
        // check col
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        // check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        //check right diagonal
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    int dp(vector<string> &board , int row){
        if(row == (int)board.size()){
            return 1 ; 
        }
        int res = 0 ; 
        for(int i = 0 , n = board[0].size() ; i < n ; i++){
            if(check(board , row , i)){
                board[row][i] = 'Q' ;
                res += dp(board , row + 1) ;
                board[row][i] = '.' ;
            }
        }
        return res ; 
    }
};