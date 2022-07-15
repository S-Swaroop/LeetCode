class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        int largest_area = 0 ; 
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j]) {
                    int area = 0 ; 
                    dfs (i , j , area , grid) ;
                    largest_area = max(largest_area , area) ; 
                }
            }
        }
        return largest_area ;
    }
private: 
    int dx[4] = {-1 , 0 , 1 , 0} ; 
    int dy[4] = {0 , -1 , 0 , 1} ; 
    bool isValid (int x , int y , vector<vector<int>> &grid) {
        return !(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0) ;
    }
    void dfs (int x , int y , int &area , vector<vector<int>> &grid) {
        area++ ;
        grid[x][y] = 0 ; 
        for (int i = 0 ; i < 4 ; i++) {
            if (isValid(x + dx[i] , y + dy[i] , grid)) {
                dfs (x + dx[i] , y + dy[i] , area , grid) ; 
            }
        }
    }
};