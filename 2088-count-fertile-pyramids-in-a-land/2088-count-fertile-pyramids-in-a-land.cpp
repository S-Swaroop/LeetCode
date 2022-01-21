class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int ans = count(grid) ; 
        reverse(grid.begin() , grid.end()) ; 
        ans += count(grid) ; 
        return ans ;
    }
private: 
    int count(vector<vector<int>> &grid){
        int n = grid.size() , m = grid[0].size() ; 
        vector<vector<int>> f(2 , vector<int>(m , 0)) ;         
        int ans = 0 ; 
        for(int i = 0 ; i < m ; i++)    f[0][i] = grid[0][i] ; 
        for(int i = 1 ; i < n ; i++){
            f[1][0] = grid[i][0] ; 
            f[1][m - 1] = grid[i][m - 1] ;
            for(int j = 1 ; j < m - 1 ; j++){
                f[1][j] = grid[i][j] ;
                 if(f[1][j] && f[0][j]){
                     f[1][j] = min({f[0][j - 1] , f[0][j + 1]}) + 1 ; 
                     ans += f[1][j] - 1 ; 
                 }
            }
            swap(f[1] , f[0]) ; 
        }
        return ans ; 
    }
};