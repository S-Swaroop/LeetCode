class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        return dp(0 , 0 , (int)grid[0].size() - 1 , grid) ;
    }
private: 
    map<tuple<int , int , int> , int> cache ; 
    int dx[3] = {-1 , 0 , +1} ;
    bool isValid(int row , int col , vector<vector<int>>& grid) { 
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())   return false ; 
        else    return true ; 
    }
    
    int dp(int row , int col1 , int col2 , vector<vector<int>>& grid) {
        if(cache.find(make_tuple(row , col1 , col2)) != cache.end()){
            return cache[make_tuple(row , col1 , col2)] ;
        }
        int cherries = 0 ; 
        cherries += grid[row][col1] + grid[row][col2] - (col1 == col2 ? grid[row][col1] : 0) ;
        if(row == grid.size() - 1){
            return cache[make_tuple(row , col1 , col2)] = cherries ; 
        }
        int res = 0 ; 
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(isValid(row , col1 + dx[i] , grid) && isValid(row , col2 + dx[j] , grid)){
                    res = max(res , dp(row + 1 , col1 + dx[i] , col2 + dx[j] , grid)) ;
                }
            }
        }
        return cache[make_tuple(row , col1 , col2)] = cherries + res ; 
    }
};