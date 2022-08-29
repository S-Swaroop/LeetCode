class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size() ; 
        for (int i = 0 ; i < n ; i++) {
            if (isValid(i , 0 , board)) {
                dfs (i , 0 , board) ;
            }
            if (isValid(i , m - 1 , board)) {
                dfs (i , m - 1 , board) ;
            }
        }
        for (int i = 0 ; i < m ; i++) {
            if (isValid(0 , i , board)) {
                dfs (0 , i , board) ;
            }
            if (isValid(n - 1 , i , board)) {
                dfs (n - 1 , i , board) ;
            }
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (board[i][j] == 'K') {
                    board[i][j] = 'O' ;
                } else {
                    board[i][j] = 'X' ;
                }
            }
        }
    }
private: 
    int dx[4] = {1 , 0 , -1 , 0} ; 
    int dy[4] = {0 , -1 , 0 , 1} ;
    
    bool isValid (int x , int y , vector<vector<char>> &board) {
        return (x >= 0 && x < (int)board.size() && y >= 0 && y < (int)board[0].size() && board[x][y] == 'O') ;
    }
    
    void dfs (int x , int y , vector<vector<char>> &board) {
        board[x][y] = 'K' ;
        for (int i = 0 ; i < 4 ; i++) {
            if (isValid(x + dx[i] , y + dy[i] , board)) {
                dfs (x + dx[i] , y + dy[i] , board) ;
            }
        }
    }
};