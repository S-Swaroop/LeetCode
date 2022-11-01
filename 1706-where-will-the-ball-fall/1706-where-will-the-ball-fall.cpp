class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans ;
        for (int i = 0 ; i < (int)grid[0].size() ; i++) {
            ans.push_back(dfs(0 , i , grid)) ;
        }
        return ans ;
    }
private:
    int dfs (int x , int y , vector<vector<int>> &grid) {
        if (x == (int)grid.size()) {
            return y ;
        } else {
            if (y + grid[x][y] >= 0 && y + grid[x][y] < (int)grid[0].size()) {
                if (grid[x][grid[x][y] + y] == grid[x][y]) {
                    return dfs (x + 1 , y + grid[x][y] , grid) ;
                } else {
                    return -1 ;
                }
            } else {
                return -1 ;
            }
        }
    }
};