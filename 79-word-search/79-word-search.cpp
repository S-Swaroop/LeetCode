class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size() ; 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[0] && dfs(i , j , 0 , board , word)){
                    return true ; 
                }
            }
        }
        return false ; 
    }
private: 
    int dx[4] = {-1 , 0 , 1 , 0} ;
    int dy[4] = {0 , -1 , 0 , 1} ;
    bool isValid(int x , int y , vector<vector<char>> &board){
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '.')   return false ;
        else    return true ; 
    }
    bool dfs(int x , int y , int index , vector<vector<char>> &board , string &word){
        if(index == word.length()){
            return true ; 
        }
        if(board[x][y] != word[index]){
            return false ; 
        }
        if(index == word.length() - 1)  return true ; 
        char temp = board[x][y] ; 
        board[x][y] = '.' ;
        bool possible = 0 ;
        for(int i = 0 ; i < 4 ; i++){
            if(isValid(x + dx[i] , y + dy[i] , board) && board[x + dx[i]][y + dy[i]] == word[index + 1]){
                possible = possible || dfs(x + dx[i] , y + dy[i]  , index + 1 , board , word) ;
                if(possible)    return true ; 
            }
        }
        board[x][y] = temp ; 
        return possible ; 
    }
};