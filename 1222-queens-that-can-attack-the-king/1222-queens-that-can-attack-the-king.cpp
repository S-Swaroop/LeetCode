class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int row = king[0] , col = king[1] ; 
        vector<vector<char>> board(8 , vector<char>(8 , '.')) ;
        for(vector<int> &i : queens) {
            board[i[0]][i[1]] = 'Q' ;
        }
        vector<vector<int>> ans ; 
        for(int i = col + 1 ; i < 8 ; i++)      
            if(board[row][i] == 'Q') {
                ans.push_back({row , i}) ;
                break ; 
            }
        for(int i = col - 1 ; i >= 0 ; i--)      
            if(board[row][i] == 'Q') {
                ans.push_back({row , i}) ;
                break ; 
            }
        for(int i = row + 1 ; i < 8 ; i++)      
            if(board[i][col] == 'Q') {
                ans.push_back({i , col}) ;
                break ; 
            }
        for(int i = row - 1 ; i >= 0 ; i--)      
            if(board[i][col] == 'Q') {
                ans.push_back({i , col}) ;
                break ; 
            }
        int i = row - 1 , j = col - 1 ; 
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q'){
                ans.push_back({i , j}) ;
                break ;
            }
            i-- ; 
            j-- ;
        } 
        i = row + 1 , j = col - 1 ; 
        while(i < 8 && j >= 0){
            if(board[i][j] == 'Q'){
                ans.push_back({i , j}) ;
                break ;
            }
            i++ ;
            j-- ; 
        } 
        i = row - 1 , j = col + 1 ; 
        while(i >= 0 && j < 8){
            if(board[i][j] == 'Q'){
                ans.push_back({i , j}) ;
                break ;
            }
            i-- ; 
            j++ ;
        } 
        i = row + 1 , j = col + 1 ; 
        while(i < 8 && j < 8){
            if(board[i][j] == 'Q'){
                ans.push_back({i , j}) ;
                break ;
            }
            i++ ; 
            j++ ; 
        } 
        board[row][col] = 'K' ;
        for(auto &i : board){
            for(auto &j : i){
                cout << j ;
            }
            cout << endl ;
        }
        return ans ; 
    }
};